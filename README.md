# mio-purple
A mod for MIO: Memories in Orbit
<details>
  <summary>End-game spoiler warning</summary>
  This mod puts the player in a state where Ati is always holding Mio. The mod is named mio-purple because Ati's primary color is purple.
</details>

## Prerequisites

- CMake 3.20 or higher
- MSVC (Visual Studio 2019 or later)
- vcpkg
- Ninja

## Building

### Using CMake Presets (Recommended)
```powershell
# Configure
cmake --preset x64-release

# Build
cmake --build --preset x64-release
```

### Running in Game

1. Copy `build/x64-release/bin/mio_purple.dll` into your MIO install's `mods` directory
2. Launch the game
