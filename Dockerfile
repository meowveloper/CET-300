FROM gcc:15.2.0



RUN apt-get update && apt-get install -y libssl-dev python3 pipx wget xz-utils

RUN pipx install compiledb

ENV PATH="/root/.local/bin:$PATH"

# Install Zig for cross-compilation
RUN wget https://ziglang.org/download/0.15.1/zig-x86_64-linux-0.15.1.tar.xz && \
    tar -xf zig-x86_64-linux-0.15.1.tar.xz && \
    mv zig-x86_64-linux-0.15.1 /usr/local/lib/zig && \
    ln -s /usr/local/lib/zig/zig /usr/local/bin/zig && \
    rm zig-x86_64-linux-0.15.1.tar.xz


