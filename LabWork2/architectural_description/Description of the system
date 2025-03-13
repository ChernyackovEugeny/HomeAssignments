Architectural Description of the Project

1. General System Description
The project is a text-based version of Five Nights at Freddy’s, implemented in C++ without graphics libraries, using ASCII visualization. The game mechanics involve processing player actions, animatronic movement, and resource management (energy, doors, cameras).

2. System Requirements and Use Cases
2.1 Functional Requirements
Camera surveillance control.
Opening and closing doors.
Limited energy supply, consumed by door and camera operations.
Animatronic movement based on predefined algorithms.
Game over when animatronics reach the player's position.
Victory when the game time expires.

2.2 Non-functional Requirements
Works in a Linux environment.
No graphics libraries; ASCII visualization only.

2.3 Use Cases
Use Case 1: Player Controls Doors
The player presses a key to control the door.
The door changes its state (open/closed).
When the door is closed, energy is consumed.

Use Case 2: Player Uses Cameras
The player presses a key to switch the camera.
The corresponding room's state is displayed on the screen.
Energy is consumed.

Use Case 3: Animatronic Moves
After a random time interval, the animatronic chooses a new position.
If the animatronic reaches the player's room, the door state is checked.
If the door is open, the player loses.
If the door is closed, the animatronic retreats.
