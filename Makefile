TARGET="//main:mpede"

all:
	bazel build $(TARGET)
debug:
	bazel build --compilation_mode=dbg $(TARGET)
clean:
	bazel clean
