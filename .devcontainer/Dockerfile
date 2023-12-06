# Dockerfile

FROM ubuntu:latest

# 替换为中国科技大学的APT源
RUN sed -i 's|ports.ubuntu.com|mirrors.ustc.edu.cn/ubuntu-ports|g' /etc/apt/sources.list

# Install basic development tools
RUN apt-get update && apt-get install -y \
    build-essential \
    curl \
    wget \
    axel \
    cmake \
    clang \
    clang-tools \
    clang-format \
    clangd-12 \
    clang-tidy \
    gdb \
    git \
    zsh \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-12 100

# Set up Oh My Zsh
RUN git clone https://mirrors.tuna.tsinghua.edu.cn/git/ohmyzsh.git &&\
    cd ohmyzsh/tools &&\
    REMOTE=https://mirrors.tuna.tsinghua.edu.cn/git/ohmyzsh.git sh install.sh

# Set up the default shell to Zsh
RUN chsh -s /usr/bin/zsh

# Expose port for potential web server development
EXPOSE 8080
