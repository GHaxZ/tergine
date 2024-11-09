# Reference

- [raylib](https://github.com/raysan5/raylib)
- [ruscii](https://github.com/lemunozm/ruscii)

# Input

- Keys are represented by their key codes (integers)
  - Key code definitions for commonly used keys
  - Character keys can be checked by just checking the character

# Drawing elements

- Canvas
  - Size (width, height)
  - Objects can be drawn on it
  - Objects can be added to the canvas
    - Objects are passed by reference, can be modified afterwards
      - Changes to the objects will be reflected in the canvas
- Objects
  - Can be drawn on canvas
  - Have many properties
    - Colors
    - Width and height (in characters)
    - Position, oriented at the top left corner of the object
    - Content (What the object looks like, string array, limited to specified width and height)

# Screen rendering

- Simple screen which can be initialized and set up
- Configurable frame rate
- Accepts canvas which will be drawn
- Canvas will be rendered every frame
  - Loop through canvas objects and draw them

# Error handling

- Result type
  - Ok - Everything went fine
  - Err - Error occured
