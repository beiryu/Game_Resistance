# Object-Oriented Programming Project: Hero Battle Game

## Game Overview

This project implements a turn-based battle game featuring heroes with various attributes and elemental affinities.

## Game Mechanics

### Heroes

- Heroes are loaded from `ListHero.txt`
- Each hero has four stats:
  - Health: Hero dies when health reaches 0
  - Attack: Damage dealt to opponents
  - Defense: Reduces incoming damage
  - Attack Speed: Time between attacks (lower is faster)
- Heroes belong to one of five elements: Fire, Water, Metal, Earth, Wood
- Elemental interactions affect hero stats in team and battle scenarios

#### Team Interactions
- Countering elements: Countered hero's attack speed increases by 10%
- Supporting elements: Supported hero's health increases by 15%

#### Battle Interactions
- Countering elements: Countered hero's defense decreases by 50%, countering hero's attack increases by 10%

### Battles

- Heroes fight in pairs based on initial order
- Winning team has more surviving heroes
- Default battle duration: 1 minute (NPC) or player-agreed time (PvP)
- Random elemental environment affects hero stats:
  - Matching element: No change
  - Supporting element: +5% health, -10% attack speed
  - Countering element: -3% health

## Game Modes

### Player vs NPC
- NPC randomly selects 3 heroes
- Player chooses 3 heroes from the displayed list

### Player vs Player
- Both players use the same interface on one PC
- Each player selects 3 heroes
- Players choose battle duration: 1, 2, or 5 minutes

## Results and Logging

- Results are displayed on screen and saved to `Log.txt`
- Log format: `<timestamp> <Player1|NPC> <Player1 Heroes> <Player2> <Player2 Heroes> <Result>`
- Players can view battle history and details by providing timestamps

## Installation

[Add installation instructions here]

## How to Play

1. [Add step-by-step instructions on how to start and play the game]
2. [Include information on how to select heroes, initiate battles, etc.]

## Configuration

- Hero list: `ListHero.txt`
- Battle log: `Log.txt`

## Contributing

[Add contribution guidelines here]

## License

[Add license information here]
