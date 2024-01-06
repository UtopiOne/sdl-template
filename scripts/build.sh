build() {
    cmake -B build -S .
    cmake --build build/
}

run() {
    build -B build -S .
    cmake --build build/
    build/game_programming
}
