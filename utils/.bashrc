# Run code
alias run = "g++ -std=c++17 -Wall -DLOCAL "$1" && ./a.out"

# Set stack size to ~2GB
ulimit -s 2000123