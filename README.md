# This file should have every command needed to get everything running.

# Required Extensions installed on local windows VSC
* CMake Tools
* C/C++ Extension Pack
* C++ Intellisense
* C++ TestMate
* Remote - WSL

# Setting up WSL
WSL gives you a Linux environment and allows you to run Linux commands from a Windows computer. It will be needed for this project. To install it, follow the instructions at https://docs.microsoft.com/en-us/windows/wsl/install. I would recommend the default "Ubuntu" installation unless you are confident enough to pick a different version. From here on out, all commands in these instructions will be through the WSL terminal, *not* the Windows terminal.

# Install required packages on WSL to compile C++ code
```
sudo apt-get -y update
sudo apt-get install -y build-essential gdb cmake libgtest-dev libgmock-dev
```

# Clone the repository
```
git clone 'https://github.com/ITT-Learning/CalculatorSkeleton.git'
```
----

# Command Line build
at the repository's root directory run...
```
cmake .
make
```

# navigate to bin and the binary should be there.
```
cd bin
./Calculator
```

# Run Unit tests.
```
cd test
./calculator_test
```

