# ✊✋✌️ Stone Paper Scissors — C++ Console Game

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue?style=flat-square&logo=cplusplus)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey?style=flat-square&logo=windows)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)

A clean, interactive console-based **Stone Paper Scissors** game written in C++. Play multiple rounds against the computer, track your score, and see who wins the final match!

---

## 📸 Preview

```
________________Round [1]________________

Player1 Choice  : Stone
Computer Choice : Scissors
Round Winner    : [Player]
________________________________________

        ____________________ [ Game Results ] __________________

        Game Rounds        : 3
        Player won times   : 2
        Computer won times : 1
        Draw Times         : 0
        Final Winner       : Player
        ________________________________________________________
```

---

## ✨ Features

- 🎮 **Multi-round gameplay** — choose between 1 and 10 rounds per game
- 🤖 **Random computer moves** — powered by `rand()` seeded with system time
- 🏆 **Round-by-round results** — see who wins each round instantly
- 🎨 **Dynamic console colors** — green for player win, red for computer win, yellow for draw
- 📊 **Final scoreboard** — full summary with total wins, losses, and draws
- 🔁 **Play again option** — restart without closing the terminal
- ✅ **Input validation** — handles invalid choices gracefully

---

## 🗂️ Project Structure

```
Stone-Paper-Scissors/
│
├── main.cpp          # Full game source code
└── README.md         # Project documentation
```

---

## 🧱 Code Architecture

The project uses **structured programming** with enums and structs for clean, readable code:

| Component | Type | Description |
|---|---|---|
| `enPlayerChoice` | `enum` | Represents Stone, Paper, or Scissors |
| `enWinner` | `enum` | Represents Player, Computer, or Draw |
| `stGameResults` | `struct` | Stores round count, wins, draws, and final winner |

### Key Functions

| Function | Description |
|---|---|
| `ReadHowManyRounds()` | Prompts and validates number of rounds (1–10) |
| `ReadPlayerChoice()` | Gets and validates the player's move |
| `GetComputerChoice()` | Generates a random move for the computer |
| `CheckWinnerInRound()` | Applies game logic to determine round winner |
| `AddWinnerInTotalResult()` | Updates cumulative score after each round |
| `WinnerBagroundEffect()` | Changes console color based on round result |
| `ShowRoundResult()` | Displays detailed result for each round |
| `ShowFinalResult()` | Prints the full game summary |
| `GetTheFinalWinner()` | Determines the overall winner after all rounds |
| `PlayGameRounds()` | Orchestrates the full game loop |
| `StartGame()` | Entry point — handles play-again logic |

---

## 🚀 Getting Started

### Prerequisites

- A C++ compiler (e.g. **g++**, **MSVC**, **MinGW**)
- Windows OS *(uses `system("color")` and `system("cls")` — Windows only)*

### Compile & Run

**Using g++ (MinGW / terminal):**
```bash
g++ main.cpp -o StonePaperScissors
./StonePaperScissors
```

**Using Visual Studio:**
1. Create a new **Empty C++ Project**
2. Add `main.cpp` to the project
3. Press `Ctrl + F5` to build and run

---

## 🎮 How to Play

1. Run the program
2. Enter the number of rounds (1–10)
3. For each round, enter your choice:
   - `1` → Stone
   - `2` → Paper
   - `3` → Scissors
4. The computer picks randomly — the round winner is shown immediately
5. After all rounds, the final scoreboard is displayed
6. Choose to play again or exit

---

## 🧠 Game Logic

```
Stone    beats  Scissors
Paper    beats  Stone
Scissors beats  Paper
```

The player with the most round wins becomes the **Final Winner**.  
If both have equal wins → it's a **Draw**.

---

## 🛠️ Technologies Used

- **Language:** C++
- **Libraries:** `<iostream>`, `<cstdlib>`, `<ctime>`
- **Concepts:** Enums, Structs, Functions, Loops, Input Validation, Randomization

---

## 🔮 Possible Improvements

- [ ] Add a **2-player local mode**
- [ ] Port to **cross-platform** (remove `system()` calls)
- [ ] Add a **score history** saved to a file
- [ ] Implement a **GUI version** using SFML or Qt

---

## 👨‍💻 Author

> Built with ❤️ as part of a C++ learning journey.

Feel free to fork, star ⭐, or contribute!

---

## 📄 License

This project is licensed under the **MIT License** — free to use and modify.
