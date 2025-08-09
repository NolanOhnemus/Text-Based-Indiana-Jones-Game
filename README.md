# Text-Based Indiana Jones Adventure

## Overview

This project is a C++ recreation of the classic **Hunt the Wumpus** game, reimagined as an Indiana Jones–inspired text adventure. It showcases algorithmic game design, interactive storytelling through the console, and thoughtful state-driven logic, all crafted for clarity and engagement.

## Objective

To deliver a compelling text-only game experience using C++ by modeling a cave-based exploration where players avoid hazards and aim to confront the elusive Wumpus. The project demonstrates procedural world generation, event-driven design, and structured command handling, delivering a robust and entertaining console experience.

## Key Features

- **Classic-Style Gameplay**: Players navigate rooms, avoid traps (e.g., guards, boulders), and track a hidden Idol through commands like "move", "shoot", and "sense".
- **Procedural Environment**: Randomized cave layout on startup ensures each game session offers a fresh challenge.
- **Hazard Dynamics**:
  - **Boulder**: Chase the player to a random position on the map.
  - **Guards**: End the game upon being caught.
  - **Sand**: Allows the player to fill a bag with sand
  - **Idol**: The player can swap the Idol with the bag of sand to win.
- **Descriptive Console Feedback**: Provides contextual sensory indicators (e.g., "You hear a rumbling in the distance") to guide decision-making.
- **Lightweight Architecture**: Built entirely in C++ without external libraries beyond the standard library.

## Technical Design

- **State Management**: Represents rooms, hazards, and adjacency using clean data structures and graph logic.
- **Command Interface**: Parses and executes player input for game actions, handling edge cases effectively.
- **Random Initialization**: Ensures fair and replayable gameplay with new cave layouts for each run.
- **User Feedback Loop**: Maintains game flow clarity with concise room descriptions and action outcomes.

## Gameplay Experience

- Prompt-based navigation with clear command feedback.
- Dynamic game world with surprises and emergent strategy.
- Ideal for learning branching logic, state-driven programming, and procedural design in C++.

---
