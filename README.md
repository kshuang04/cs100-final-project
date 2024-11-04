# \<Path of Pain\>
 
  Authors: \<[Josiah Kou](https://github.com/JosiahKou)\>, \<[Glen Bautista](https://github.com/TrainGamer851)\>, \<[Red Su](https://github.com/redddddsu)\>, \<[Sky Huang](https://github.com/kshuang04)\>, \<[Oliver Ren](https://github.com/O1iver-R)\>

## Project Description
  This project is interesting to us because an RPG rouge like is a type of game our members like to play. We want to take insperation from games like Path of Exiles and Slay the Spire. We think an RPG game is a good idea because it allows us to be creative, implementing many different ideas into our game.

 We will be using C++ and VScode for the entirety of our project. We will make everything text based.

 Our project will take in inputs throughout the entirety of the game. At the beginning, it will ask for a name and class. During the game, it will ask whether the user wants to go a certain path. During battles, the user will be asked what action they want to perform, if its using an item, casting a spell, or wielding a weapon. All inputs, besides name, will be selected using a number after being presented a list with numbers. As for outputs, because it is text based, all of the monsters, health, gold, actions, and paths will be shown through text throughout the game. We will output things such as:\
 "Welcome to the game"\
 "Player Health: 100/100"\
 "0 Training Grounds"\
 "Monsters in this stage:"\
 "1. dummy (Health: 30, Attack: 5)"\
 "2. dummy (Health: 30, Attack: 5)"\
 "Choose an action:"\
 "1. Attack"\
 "2. Items"\
 There will also be special dialouge for events like shopkeepers. They may say:\
 "What do you want to buy?"\
 "1. helmet"\
 "2. health potion"\
 "3. antidote"\
 "4. No shopping for now"\
 As a response, the user will choose a number to purchase anything.

 

 Our project will include the basic features of an RPG. There will be a gold system will be used in shops. There will be a variety of monsters across a few regions that will scale with stage level. There will be a class system that have different base stats. There will be a battle system that allows the use of items and attacking. As for special features, we will have random encounters that will trigger special events and a path system that allows the user to pick what they want to do at every stage. After beating every stage, the player can pick up a random amount of loot.
  ## Phase II
  In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
  * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
  * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
    * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
    * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
  * Each team member needs to submit the Individual Contributions Form on Canvas for this phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase  II, and a description of their contributions. Remember that each team member should submit the form individually.
  * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
    * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
    * The second check-in should be scheduled with a reader. During that meeting you will discuss:
      * The tasks you are planning for the first sprint
      * How work will be divided between the team members
## User Interface Specification
  Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from the User Interface Design Document Template of CMSC 345 at the University of Maryland Global Campus)

### Navigation Diagram
 ![User Navigation Diagram](images/userNavigationDiagram.png)
 The User Navigation Diagram represents the flow of the game iself of how the roguelike game is played and what steps are taken to go from one part to an another. This includes any player inputs or game mechanics to show what things are output in a certain scenario like purchasing items from a shop, fight monsters in a battle, or changing equipment before proceeding to the next level. It also shows the parts to be within one of 6 main screens used here. The "Start Screen" is used to for starting the program or game. The "Player Equipment Screen" is used for the players to change items or use items before proceeding tothe next level. The "Shop Screen" is used for players to purchase and/or sell items from the Shop. The "Battle Screen" is used to show the actions from the players and monsters in a fight to see the outcomes. The "Game Over Screen" is used when the game ends from either the player lost or the last level is completed.

### Screen Layouts
The general layout for our screens will consist of details about the current state of the game followed by a user prompt and the choices available for the user to make. The user will then input their choice as numerical input through the terminal.
For example, these are the screens that the user will see at the start and end of the game:\
![Start Screen](images/startScreen.png) ![Lose Screen](images/loseScreen.png) ![Win Screen](images/winScreen.png)\
Here, the user is given two choices: start the game (or restart the game) or to exit the game. The user will enter a numerical input to make their choice.

Our battle layout will look like this:\
![Battle Screen](images/battleScreen.png)\
Here, the user is shown information about the enemies' current health as well as their player's current health. The user is also prompted to choose between two actions: attack or use an item they possess. The attack option will decrease the enemies health and start the enemies turn. If the user chooses to use an item, they will be shown the inventory screen which is described in the next section. 

If the user were to want to use an item in battle, they will be greeted with the following screen:\
![Inventory Screen](images/inventoryScreen.png) \
This screen shows how our program would look if a player were to input their choices. The user is first shown how many of each item they have possess, and then prompted to choose an item to use. This image shows that the user chose to use an item they currently have none of, so the program notifies the user that they have no items to use of that type, and then reprompts the user to choose an item. After the user choosed a valid action, the program will show validation of their input. In this case, text output to the terminal showing that the user used a health potion. The user also has the option to return to battle after using the items they desire. This action will return the user to the battle screen and initiate the enemies' turn. \
The enemies' turn screen will look like this:\
![Enemy Turn Screen](images/enemyTurnScreen.png)\
This screen gives information to the user about the enemies' action. There is no user input for this screen. In this case, Enemy 1 attacked Player and Player lost 20 health. After the enemies' turn, if the player survives the attack, the battle screen will be shown again with the new updated health and the choices the user is able to make. 

Finally, another one of our main screens will be the shopkeeper's screen:\
![Shopkeeper Screen](images/shopkeeperScreen.png)\
This screen follows our general layout. If the user chooses to visit the shopkeeper after completing a level, they will be greeted with this screen that shows how much currency they currently have and the items avaiable to purchase from the shopkeeper. Again, the user is prompted to choose an option and input their choice as a numerical input. If they choose to buy an item, that item will be added to their inventory and the cost of that item will be deducted from their total currency. The user is also given the choice to sell items that they currently have in exchange for currency. Finally, the user is given the choice to leave the shopkeeper and continue their journey through Path of Pain.


## Class Diagram
  Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
  ![UML Diagram](images/UMLDiagram.png)/

  The core of the game is centered around the RogueGame class, an abstract base class that serves as the main entry point and game logic.

  The primary components driving the gameplay are the Player class, representing the user-controlled character, and the Level class, where the core gameplay unfolds.
  
 
  ## Phase III
  You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.

  The Player class encapsulates the player's attributes and capabilities, such as health, attack power, and available moves. This class interacts with a specialized CharacterClass class, which defines the player’s starting stats, abilities, and moveset.

  The moveset is further defined by an Attack class, which organizes individual attack moves available to the player.

  Additionally, each player can possess various items, represented by an Item class. The Item class acts as a parent class for specific item types like health, attack, and defense boosters, allowing for flexible item management and customization.

  The Level class handles the environment where gameplay events occur. Each level contains a list of enemies, which are instances of the Enemy class, detailing enemy attributes and behavior.

  Levels may also include rewards, which often consist of items that the player can collect. These items derive from the Item class, linking gameplay rewards with the player’s inventory.

  The Level class has a reference to the Player class, enabling direct interaction between the player and the game's environment. This reference allows the level to access the player's current state, respond to player actions, and apply changes based on gameplay events. The level can also give rewards to the player. The player also has access to the level, where the player can affect the enemies that are within the level. 

 
  BEFORE the meeting you should do the following:
  * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
  * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
    * A new class diagram incorporating your changes after considering the SOLID principles.
    * For each update in your class diagram, you must explain in 3-4 sentences:
      * What SOLID principle(s) did you apply?
      * How did you apply it? i.e. describe the change.
      * How did this change help you write better code?
  * Perform a new sprint plan like you did in Phase II.
  * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
  * Each team member should also submit the Individual Contributions Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
 During the meeting with your reader you will discuss: 
  * How effective your last sprint was (each member should talk about what they did)
  * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
  * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
  * What tasks you are planning for this next sprint.

 
  ## Final deliverable
  All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
  Before the demo, you should do the following:
  * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
  * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
  * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
  Screenshots of the input/output after running your application
 ## Installation/Usage
  Instructions on installing and running your application
 ## Testing
  How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
