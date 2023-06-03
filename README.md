# BedrockHeaders
📃An open repository for 1.14.60.5 Header's for writing mods with Zenova

## How to use
1. Run `git submodule add https://github.com/FrederoxDev/BedrockHeaders` to add this repo as a submodule
2. Modify your IncludeDir path in CMakeLists.txt to include the new path `set(IncludeDir BedrockHeaders/inc)`
3. Do the same for the maps folder `set(maps_directory "${CMAKE_CURRENT_SOURCE_DIR}/BedrockHeaders/maps")`

## Contributing
- Keep files neat, split large classes among multiple files if appropriate
- Seperate symbol maps up, one per class
