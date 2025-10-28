FROM ubuntu:24.04

# Install all development tools and dependencies in a single layer
RUN apt-get update && apt-get install -y \
    build-essential \
    wget \
    software-properties-common \
    gnupg \
    ca-certificates \
    git \
    cmake \
    ninja-build \
    cppcheck \
    sudo \
    gcc-14 \
    g++-14 \
    clang-19 \
    clang++-19 \
    clangd-19 \
    clang-format-19 \
    clang-tidy-19 \
    libc++-19-dev \
    libc++abi-19-dev \
    gdb \
    lldb-19 \
    valgrind \
    && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-14 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-14 100 \
    && update-alternatives --install /usr/bin/clang clang /usr/bin/clang-19 100 \
    && update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-19 100 \
    && update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-19 100 \
    && update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-19 100 \
    && update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-19 100 \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Download and install Google Test from source
RUN cd /tmp \
    && wget https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz \
    && tar -xzf v1.15.2.tar.gz \
    && cd googletest-1.15.2 \
    && mkdir build && cd build \
    && cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local \
    && make -j$(nproc) \
    && make install \
    && cd /tmp \
    && rm -rf v1.15.2.tar.gz googletest-1.15.2

# Verify installations
RUN gcc --version && g++ --version && clang --version && clang++ --version && cmake --version

# Declare build args for dynamic UID/GID
ARG USERNAME
ARG UID
ARG GID

# Remove default 'ubuntu' user to avoid UID/GID conflicts when creating a new user matching the host
RUN userdel -r ubuntu || true

# Create a user matching host UID/GID
RUN groupadd --gid ${GID} ${USERNAME} || true && \
    useradd \
      --create-home \
      --gid ${GID} \
      --groups sudo \
      --no-log-init \
      --shell /bin/bash \
      --uid ${UID} \
      ${USERNAME} && \
    echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers && \
    mkdir -p /home/${USERNAME}/workspace && \
    chown -R ${UID}:${GID} /home/${USERNAME} && \
    sed -i 's/#force_color_prompt=yes/force_color_prompt=yes/' /home/${USERNAME}/.bashrc

USER ${USERNAME}
WORKDIR /home/${USERNAME}/workspace

# Default command
CMD ["/bin/bash"]
