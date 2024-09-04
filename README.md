# DNDRepo
The program is a simplified realisation of the game „Dungeons and dragons“ for the Object-Oriented course at Sofia university. In the game, the hero wanders through the map, collects items, fights monsters and uses spell or weapons. Cells that haven't yet been discovered are marked with a ‘?’, the walls of the labyrinth with ‚#‘, cells inhabited by monsters - ‚M‘ and cells, where there is a collectible - ‚T‘. The character can choose between three classes/races – human, mage or warrior, each of them with different base stats. Every spell costs 5 mana, and when the character is not in combat and wanders through the map, he restores 1 mana per step.
The character has inventory ( weapon, spell and armor), which add bonuses to their physical attacks (weapon), magical attacks (spell) or defense (armor), when in combat.
On application startup, if there exists a backup file from a previous session, the user has the opportunity to restore said session. Files are intended to be used as “save files” from video games, so they store information about the character and the current layout of the map. When started, the player loads the corresponding “save file”, which can be altered through the command interface:
Потребителят може да избира измежду 10 команди, а именно:
1.	open `<file>`
2.	close
3.	save
4.	saveas `<file>`
5.	help
6.	exit
7.	`<direction>`
8.	restore
9.	visualize
10.	generate

If the user input does not match any of the predefined commands, an ‘Invalid command!’ message is displayed.

  
  
  
  The class Hero represents the playablе character. Depending on the chosen race, the default stats differ:
Human – Strength: 30, Mana: 20, HP: 50, Spellpower: 20
Mage – Strength: 10, Mana: 40, HP: 50, Spellpower: 40
Warrior – Strength: 40, Mana: 10, HP: 50, Spellpower: 10
The character begins their journy at level 1, and has an inventory where only one spell, weapon and armor acan be stored. Upon creation, the character has no armor - just a spell and weapon with bonuses of 20 percent. 

  
  GameEngine is the class responsible for handling game logic, which includes character navigation, map and level generation, actions corresponding to the current cell, such as battle initiation or item pickup. Each generated level is stored in a file with the name „gameFile<number>.txt“, where <number> is the number of the generated level.
