# timberman.game 🕹️
<table>
  <tr>
    <td>
      <img src="https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExZXNoeHFvM2VjNnFrMGNyODI0Z2NzYTgxN25kN3R6YnU0eW0xc3RmcyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/aCRtBu8bo5JiLjfe8N/giphy.gif" alt="GIF" />
    </td>
    <td>
      Timberman is a fun and engaging game where players take on the role of a lumberjack chopping down a tree while avoiding obstacles. It challenges quick thinking and reflexes, making it a perfect pastime for gamers of all ages.
    </td>
  </tr>
</table>



## Screenshots

| Gameplay Demo                                       | Game Interface                                     |
|----------------------------------------------------|--------------------------------------------------|
| ![Gameplay](https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExOWdpdjVmMWl1cWV1Z2RndWd0YWFzM3Q0eWl2djhjNGJ3b2RyeWk1biZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/NytMLKyiaIh6VH9SPm/giphy.gif) | ![Game UI Placeholder](https://via.placeholder.com/300x200) |

---




## About the Game

Timberman is a fast-paced arcade game that challenges your reflexes. This implementation is written in C++ and offers a console-based interactive experience. The game's objective is to chop down the tree as much as possible without getting hit by its falling branches.

---

## Features

- **Console-Based Gameplay**: Simple and lightweight implementation using C++.
- **High Score Tracking**: Keeps track of the player's highest score.
- **Dynamic Difficulty**: The game speeds up as you progress.
- **Cross-Platform Compatibility**: Runs on any system with a C++ compiler.
- **Customizable Settings**: Modify game parameters such as speed and difficulty.

---

## Game Rules

1. Chop the tree by pressing the left or right arrow keys.
2. Avoid getting hit by the falling branches.
3. The game ends if you are hit by a branch.
4. Try to achieve the highest score possible.

---

## Installation

Follow the steps below to set up and run the Timberman game on your local machine:

### Requirements

- A C++ compiler (e.g., GCC, Clang, or MSVC)
- A terminal or console environment

### Steps

1. Clone the repository:
   ```bash
   git clone https://github.com/srikxcipher/timberman.git
   cd timberman
   ```

2. Compile the source code:
   ```bash
   g++ -o timber timber.cpp -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
   ```

3. Run the game:
   ```bash
   ./timber
   ```

---

## How to Play

1. Open the game in your terminal.
2. Use the following controls to play:
   - **Left Arrow Key**: Chop the left side of the tree.
   - **Right Arrow Key**: Chop the right side of the tree.
3. Keep chopping while avoiding the branches.
4. The game speeds up as your score increases.

---

## Project Structure

The repository is organized as follows:

```
timberman/
├── res/             # Game assets
├── docs/            # Documentation files

```


- **`timber.cpp`**: Contains the game logic and mechanics.


---

## Contributing

Contributions are welcome! If you'd like to improve this project, please follow these steps:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add feature-name"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Open a Pull Request.
---

## Contact

For any queries or feedback, feel free to reach out:

- **GitHub**: [@srikxcipher](https://github.com/srikxcipher)

---

## License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute this software as long as the original license is included.

