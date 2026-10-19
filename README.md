# DeviceMonitor

A device monitoring system composed of a C++ agent and a Node.js/TypeScript backend.

## Project Structure

```
DeviceMonitor/
├── agent/          # C++ agent (CMake)
│   ├── src/
│   └── CMakeLists.txt
├── backend/        # Node.js + TypeScript backend
│   ├── src/
│   ├── package.json
│   └── tsconfig.json
└── .vscode/        # VS Code configuration
```

## Prerequisites

### Backend
- Node.js 18 or higher
- npm

### Agent
- CMake 3.10+
- C++ compiler (g++, clang, or MSVC)

## Installation & Running

### Backend

```bash
cd backend
npm install
npm run dev
```

### Agent

```bash
cd agent
mkdir build && cd build
cmake ..
cmake --build .
```

## Technologies

- **Backend**: Node.js, TypeScript, Express, SQLite, Zod
- **Agent**: C++, CMake

## License

MIT