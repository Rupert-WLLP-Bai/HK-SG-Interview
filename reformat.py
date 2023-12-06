import concurrent.futures
import subprocess
import os
from pathlib import Path
from datetime import datetime

# 配置项
max_workers = 8  # 最大并发数
build_dir = "build"
log_dir = "reformat_logs"

# 开始运行的时间
start_time = datetime.now()

# 复制compile_commands.json到当前目录
src_file = f"{build_dir}/compile_commands.json"
dest_file = "./compile_commands.json"
try:
    Path(dest_file).write_text(Path(src_file).read_text())
    print(f"compile_commands.json copied to the current directory.")
except FileNotFoundError:
    print(f"Error: {src_file} does not exist.")
    exit(1)

# 创建日志目录
Path(log_dir).mkdir(exist_ok=True)
print(f"Log directory created at {log_dir}.")

def process_file(filename):
    start = datetime.now()
    base_name = os.path.basename(filename)
    log_file_path = f"{log_dir}/{base_name}.log"
    
    with open(log_file_path, "w") as log_file:
        # 执行clang-tidy
        subprocess.run(
            ["clang-tidy", filename, "-fix", "--", "-std=c++11"],
            stdout=log_file,
            stderr=subprocess.STDOUT
        )
        
        # 执行clang-format
        subprocess.run(
            ["clang-format", "-i", filename],
            stdout=log_file,
            stderr=subprocess.STDOUT
        )

    end = datetime.now()
    duration = end - start
    return (filename, duration.total_seconds(), log_file_path)

# 获取所有.cc文件
cc_files = list(Path(".").rglob("*.cc"))

# 使用线程池并行处理文件
results = []
with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
    futures = [executor.submit(process_file, str(file)) for file in cc_files]
    for future in concurrent.futures.as_completed(futures):
        results.append(future.result())

# 输出表格标题
print("\nFile Processing Summary:")
print("{:<40} {:<15} {:<60}".format("Filename", "Duration(s)", "Log File"))

# 输出每个文件处理结果和持续时间
for result in results:
    print("{:<40} {:<15.2f} {:<60}".format(*result))

# 删除compile_commands.json
try:
    os.remove(dest_file)
    print(f"\ncompile_commands.json removed.")
except OSError as e:
    print(f"\nError deleting {dest_file}: {e}")

# 输出总结信息
end_time = datetime.now()
total_duration = end_time - start_time
print(f"\nTotal files processed: {len(results)}")
print(f"Total time taken: {total_duration.total_seconds():.2f} seconds")
