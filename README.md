# TodoList-wxWidget

A simple **To‑Do List** desktop application built with **C++** and **wxWidgets**.

## Features

- Add new tasks
- Mark tasks as completed (if supported in the UI)
- Remove tasks
- Lightweight native desktop GUI via wxWidgets

> Note: The exact feature set depends on the current implementation in the repository.

## Tech Stack

- **Language:** C++
- **GUI Framework:** wxWidgets

## Prerequisites

- A C++17 (or newer) compiler
- wxWidgets development libraries
- CMake (if the project uses CMake) or your preferred build system/IDE

## Build & Run

Because build tooling can vary by platform and project setup, use one of the approaches below depending on what the repository contains.

### Option A: CMake (common)

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

Run the produced executable from the `build/` directory.

### Option B: wxWidgets IDE project

If the repo contains an IDE project (Visual Studio, Code::Blocks, etc.), open the project and build/run from there.

## Project Structure

Typical wxWidgets projects are organized like this (your repo may differ):

- `src/` — application source code
- `include/` — headers
- `assets/` — icons/resources

## Contributing

Contributions are welcome.

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Open a pull request

## License

No license file was detected. If you intend others to use, modify, or distribute this code, consider adding a LICENSE file (e.g., MIT, Apache-2.0, GPL-3.0).
