# Maze on paper

Is a logical game played with pencil (or pen) and paper by three or more participants. One participant, known as the "game master" or "game leader", designs the labyrinth map, sets the game rules, and announces results of every move. The other players attempt to traverse the labyrinth, trying to reveal the labyrinth design and achieve the objective (usually, it consists of finding the treasure and exiting the labyrinth with it).

## Game setting

At least two players and the game master (three people altogether) are required. For beginners that might be enough but for advanced players it is recommended to have at least three players. Having more than five players (six people) is not advisable (but possible).

Each participant should have a notepad or notebook, preferably with graphed paper (as a matter of fact, using graphed paper is highly recommended), and a pen or a pencil (pencil with a soft eraser is recommended).

Usually, when there are N participants they play a series of N games where they take turns serving as game masters (one game each). The set of rules is agreed upon before the series and should not be changed between the games.

## Basic Rules

* The game master creates the labyrinth, which is designed on a square board surrounded by monolithic wall with one or several exits.
* The game master and the players must decide which set of rules they are using. There are several variations of Labyrinth's rules. Most important of them are the ones that deal with consequences ofimpossible move requests and the ones that define which non-empty cell types are allowed.
* At the beginning of the game the game master informs the players of the following: size of labyrinth, number and length of Wormhole chains, number and length of River(s) (if any), and any otherspecial parameters (number of arsenals, size of starting weapon kit etc.)
* Players make their moves in turn.
* In one move player can move his/her marker to the neighboring cell, that is to the one that has a common border with his current cell. Cells that border diagonally are not neighbors.
* After every move request the game master informs the player whether his move is possible. If it is, then he is informed on the type of the field his marker ended up on - regular field, Arsenal, Riversource, River end, Wormhole, exit etc.). If it is not, he is told whether the obstacle is the regular wall or the monolith (labyrinth boundary). If "relaxed" rules are used the player is then allowedto repeat his move request (command) until he is able to finally move. If "rigid" rules are used, the player loses his turn.
* If the player shoots then he is informed of the result, such as some other player is shot (wounded or killed).
* The next turn should not start until everyone has recorded all necessary information resulting from the last turn. Players are allowed to ask the game master to repeat the very last move's requestsdirectives and results but this should not be abused. On the other hand, the game master has to make sure that the game flow is not interrupted by long pauses when other players are waiting for someextended period of time so that one of them can finalize his/her notes.
* All game master announcements are made aloud and publicly. There must be no secret information being passed from the game master to the players during the game. The game master is allowed to publiclyask a player for some data and receive their answers in secret - however, this is not encouraged and is reserved only for special situations when the game master has lost track of some moves orparameters and needs some extra information to restore the proper state of the game. If that happens, the game master must make sure that as a result of this communication the player does not receiveany additional information.
* Players cannot form alliances and/or exchange any information in secret.

## Game objective

Game ends when there is only one of the players left alive, or when one of the players exits labyrinth with the Treasure(s).

Each player should keep track of everyone's movements and directives/requests, trying to recreate the labyrinth structure in his/her own notepad. Good understanding of logic, planar (two-dimensional) geometry and orientation would certainly be a big advantage when a player tries to "glue" together pieces of the labyrinth from smaller maps of their own and other players' trajectories

## Labyrinth structure

![Example of Labyrinth game map](https://github.com/BSolonenko/MazeOnPaper/blob/master/TerraIncognitaExample.jpg "Example of Labyrinth game map")

* Labyrinth is built on a square-shaped playing field. Size of the field determines complexity and length of the game. It can be as small as 4 x 4, and usually it is not larger than 10 x 10 or 12 x 12.
* Every cell in the labyrinth belongs to one of the following types:
    * Empty cell
    * Wormhole. The Wormholes are organized into several Wormhole sets, each one of them being a cycle consisting of several Wormholes. In the figure above there are two Wormhole chains - W with four Wormholes marked w1-w2-w3-w4 and V - three Wormholes marked v1-v2-v3. Having Wormholes is not mandatory
    * River (or River source or River end); River consists of several cells arranged in a chain such that any two successive cells in the chain are neighbors. River cannot intersect itself and should not be excessively long. River has a fixed direction from its source to its end. In the figure above one River with seven cells is shown in blue, its source is marked with letter "s" and the end with letter "e". Having Rivers is not mandatory
    * Hospital (variations without a Hospital are common)
    * Arsenal, which contains certain weapons. Usually Arsenal has an unlimited number of weapons but each visitor is only allowed to take a certain number of them when they enter it (there are many variations related to the Arsenal specifics)
    * Treasure. At least one of empty cells must be marked as Treasure
* Wall can be erected between any two neighboring cells
* Outside wall which is called monolith must have at least one exit, meaning that one of its segments has to be absent so that players can leave the labyrinth

## Beginning of the game

After learning the labyrinth parameters each player (in secret) tells the game master the cell where he wants his/her marker to be placed at the beginning of the game. One common variation - game master places the players' markers randomly so the players do not know their initial positions.

After this the game master makes announcements about type of cells where each player is located, and if necessary informs players whether their markers have been automatically moved or affected in any other way.

Each player is equipped with starting kit (arsenal) which contains a specific set of weapons. Example: one grenade, five bullets and a knife. Variations are possible (absence of knife etc.).

## Game flow

Players make their moves in turn. They can:

* make a step (by issuing request/directive/command "up", "down", "left" and "right" (in case if labyrinth is 3-dimensional this set of requests/commands has to be changed accordingly and agreed upon to avoid any confusion)
* or skip their step (request "skip a step")

They can also

* shoot in any direction (directive "shoot left/right/up/down"). The bullet then flies into the defined direction until it hits a wall or a player. If it hits a player, he/she is declared wounded (or in some variations, killed). Game master announces the result of the shot. Player can shoot before and after he/she makes a step in some direction. Under some rules player is allowed to make that decision after he/she is informed about consequences of the step.
* strike with knife (directive "use knife"). If some other player is in the same cell, he will be wounded (killed). The used knife is discarded.
* blow up a wall in any direction (directive "throw grenade left/right/up/down"). Game master then announces the result of the action, such as "Wall on the left is destroyed" or "No wall in that direction. Wasted grenade" or "Monolith. Wasted grenade". In most variations using a grenade does not wound or kill other players.

Any combination of the weapon use directives can be used together with any type of step request.

When a marker's step part of the request/directive is given the game master tries to move the marker in the requested direction. Then the game master announces the result. The result could be

* "step executed" (or "moved" or "done")
* "step executed, wormhole" (or "arsenal" or "river" or some other non-trivial type of cell)
* "step impossible, wall"
* "step impossible, monolith"

If step is impossible then what happens next is defined by the agreed upon set of rules. Under "relaxed" step rule the player is allowed to try again until his marker finally moves. Under "restricted" step rule he can only make one step request and then it is the next player's turn.

The consequences of the step:

* If player's marker moved to the Wormhole then the marker is automatically moved to the cell with the next Wormhole in that Wormhole cycle (the index of the Wormhole or any other information is not divulged). If current position is the last one in the chain, the marker is moved to the first Wormhole of the chain (hence the "cycle"). Under "restricted" step rule if step request from a Wormhole cell cannot be executed then the marker automatically "jumps" to the next Wormhole. Player also can decide to skip the step part and then his marker will also automatically move to the next Wormhole in the cycle (regardless of which step rule is implemented).
* If marker is moved into a River, it is then automatically moved two cells down the River chain. If one of these cells is the River end then the marker stops there. If marker was already in the River (but not at the River end) the player can elect to skip the step - then the marker will flow down the River accordingly.
* If marker is in the Arsenal then his starting kit is restored or he is granted an additional kit.
* If a wounded player is in the Hospital his/her health is restored. A wounded player cannot use weaponry or carry the treasure.

If a player carries Treasure and he is wounded, Treasure stays in that cell until it is picked up. If a player was wounded while he was in the River then Treasure starts flowing down the River (two cells after every move) and stops at the River end until it is picked up.

The game master's objective is to create a labyrinth which has the following qualities

* all cells can be reached without having to use grenades (if Arsenal is available then one enclosure is permissible but then the Arsenal has to be accessible)
* it is not too simple (minimal number of walls, no Wormholes etc.) and not too complicated (excessive number of walls, too many Wormhole cycles, very long River, exotic creatures etc.)
* labyrinth design should account for the number of players, for their experience, and for the desired amount of time

## Rule modifications

Game of Labyrinth can be very easily modified in many ways. Most common modifications are:

* "relaxed" step rule allows to repeat step request if the previous one is not possible to execute;
* size of starting weapons kit (and Arsenal) can vary. In some variations there is no starting weapons kit and Arsenal size is equal to three copies of every permissible weapon type
* using no more than one Wormhole cycle
* using no more than one River
* using no more than one Arsenal, Hospital or Treasure
* objective of the game could be changed from exiting the Labyrinth with one Treasure to exiting it with all Treasures etc.
* there can be also a so-called False Treasure. Its "false" nature is announced only after a player who carries it exits the labyrinth; in that case with his next move the player must step back into the labyrinth and continue playing
* adding another cell type called "Swamp". Stepping into that cell results in skipping the next move
* Labyrinth could have three dimensions; this variation is for hardcore players only. Not only it is very complicated to create and manage, but to keep trajectory records and play there is also very hard
* Arsenal could have bags of "cement" that will allows to build up walls
* If there are many Arsenals, some of them could carry bullets only or grenades only, etc.
* New types of weapons can be introduced such as boomerang; boomerang flies in the given direction for the preset number of cells and will either hit the wall and fall down or return. Any player in its way will be wounded or killed
* Labyrinth can be populated with "creatures". An example - Bear. Bear moves around labyrinth either via some fixed trajectory or it simply repeats (when it can) other players' moves. If a player and Bear are in the same cell, the player is wounded. If Bear is wounded, it is immediately moved back to his Bear Cave (some cell pre-selected by the game master) and from there it starts its trajectory all over again. Other type of "creature" (much friendlier) is Leprechaun who when encountered will reaveal to the player the location (relative to player's current position) of the nearest Treasure - but it will not disclose the way of getting there. Leprechaun's trajectory is defined by some simple preset rules. Leprechaun can be killed
* Some internal walls are declared indestructible
* Some walls have one-way doors meaning that the player could move through them but only in one direction
* Some walls can have windows so that bullets go through them. A player still cannot walk through such a wall
* Game master could give only partial information to the players, or give them extra information. For example, he will not make any distinction between monolith and regular walls. Or he could tell them they have encountered other player's corpse, or that they have returned to their original position etc.
* Some restrictions can be imposed on geometry of the labyrinth. For instance, Rivers only flow from North to South, Rivers must be straight, Wormholes cannot be too close to each other etc. If any design restrictions were used they must be publicly declared before the game

## Rules classification and advice

One of the most common attempts at rule sets classification is done according to the following (expandable) system:

* General
    * G1 - initial marker positions are determined by players
    * G2 - initial marker positions are chosen by the game master
    * G3 - three-dimensional labyrinth
* Step Requests
    * S1 - Player is allowed to make step requests until his marker is moved or all possible requests are exhausted (marker is walled in). This is called "relaxed" step rule
    * S2 - Player is only allowed to make one step request. This is called "restricted" step rule
* Flow
    * F1 - no Wormholes, no Rivers
    * F2 - only one chain of Wormholes is allowed
    * F3 - several chains of Wormholes, no Rivers
    * F4 - several chains of Wormholes, one River
    * F5 - no restrictions on Wormholes or Rivers
* Victory
    * V1 - Victory (game objective) is achieved when a player exits labyrinth with (genuine) Treasure, or all other players are eliminated
    * V2 - Victory is achieved when a player exits labyrinth with (genuine) Treasure
    * V3 - Victory is achieved when a player exits labyrinth with all Treasures collected
    * V4 - Victory is achieved when a player exits labyrinth with all Treasures collected, and all other players are eliminated
* Treasure
    * T1 - Only one (genuine) Treasure is allowed
    * T2 - One genuine and one false Treasure are allowed
    * T3 - Any number of Treasures, genuine and false, is allowed
* Arsenal
    * A1 - No Arsenals
    * A2 - One Arsenal with unlimited weapons
    * A3 - One Arsenal with only one extra kit per each player
    * A4 - Multiple Arsenals with unlimited weapons
    * A5 - Multiple Arsenals with only one extra kit per each player
* Health
    * H1 - No health tracking
    * H2 - No wounding, if a player is shot he dies (is eliminated from the game)
    * H3 - Double wounding means death
    * H4 - One Hospital
    * H5 - Multiple Hospitals are allowed
* Weapons
    * W1 - No weapons
    * W2 - Knives are permitted
    * W3 - Starting weapons kit (SWK) is empty
    * W4 - SWK has one grenade, no bullets
    * W5 - SWK has one grenade and five bullets
    * W6 - SWK has one grenade, five bullets, and one knife
    * W7 - SWKs are trophies which means player is allowed to take them from the dead players but only in case he steps into the corresponding cell
    * W8 - Using grenade kills another player who is located in corresponding neighboring cell
    * W9 - Player is only allowed to use weapons after the move
* Obstacles
    * O1 - Walls (but not monolith) can be blown up by grenades, several exits possible
    * O2 - Walls (but not monolith) can be blown up by grenades, only one exit
    * O3 - Indestructible internal walls are possible
    * O4 - Using cement is permitted
    * O5 - One-way doors
    * O6 - Walls can have windows
    * O7 - using exotic creatures (their types must be declared before the game starts)

Beginners should start with the following set of rules

**BASIC**
    G1-S1-F1-V1-T1-A1-H1-W1-O1

and then move on to

**BASIC-W**
    G1-S1-F1-V1-T1-A2-H2-W5-O1

Advanced beginners should consider switching to G2, F2 or F3, H3 and/or H4, W2/W6, O2 or O3. Change to S2 does not really change complexity too much, but using this option will likely make the matches last longer.

More advanced users should go with something like

**CLASSIC**
    G2-S1-F3-V1-T2-A2-H2-W57-O2

and then if so desired proceed to

**CLASSIC-X**
    G2-S2-F4-V3-T3-A5-H34-W67-O24

The more complicated is the set of rules chosen, the greater (and more taxing) is the responsibility of the game master. The game master must keep track of all moves, of various parameters like the state of weaponry and arsenals, of location(s) of treasure and SWKs, health of the players and everything else that can have any bearing on the game flow. Of course, it is possible to create all sorts of superbly exotic and complicated rules (something along the lines of G2-S2-F5-V4-T3-A5-H34-W3789-O134567) but that can end up in a huge mess when some players do not remember nor understand all the rules, where the game master loses track of some parameters or creatures or rebuilt walls. This is not a "shoot'em up" or an RPG - what this game is really about is the ability of the players to use logic and basic geometry to piece together one large map from several smaller portions.

At the same time the player also needs to somehow determine what level of knowledge the other players possess because it will most likely affect player's own strategy to find a treasure or to eliminate competitors. For instance, if player A knows where another player B is located then A could make a move with intention to kill B after A's next step. With that move A might temporarily expose his/her position to B and if B has had already calculated A's position then B will be able to shoot first. Other similar considerations are possible as well.

## External links

* [Maze on paper in Russian](http://thejam.ru/igry-na-bumage/labirint-dlya-dvux-igrokov.html)