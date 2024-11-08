# Reference

- [raylib](https://github.com/raysan5/raylib)
- [ruscii](https://github.com/lemunozm/ruscii)

# Input

- Keys are represented by their key codes (integers)
  - Key code definitions for commonly used keys
  - Character keys can be checked by just checking the character

# Display

- Canvas
  - Size (width, height)
  - Objects can be drawn on it
  - When passing an object for drawing, a position can be specified
    - Position is located at the top left corner of the object
- Objects
  - Can be drawn on canvas
  - Have many properties
    - Colors
    - Width and height (in characters)
    - Content (What the object looks like, string array, limited to specified width and height)

# Error handling

- Result type
  - Ok - Everything went fine
  - Err - Error occured
