#pragma once

// The first combat of the game, a tutorial introduction to the rules of the game
// returns false if the user lost, otherwise, returns true
bool tutorial();

// Default combat, takes 2 dialogues to be displayed during the combats
// And one enemy name, the third argument
// The first one is displayed at the beginning of the combat
// The second one, when the cards are shown
// The third one, to display the name of the enemy you're fighting against
// returns false if the user lost, otherwise, returns true
bool combat(const char *, const char *, const char *);

// Scripted combat, just like the default, but takes one bool as the first argument
// true if you want the player to win, false if you want the enemy to win
bool scombat(bool, const char *dialogue1, const char *dialogue2, const char *enemy);
