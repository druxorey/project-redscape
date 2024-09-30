#pragma once

// The first combat of the game, a tutorial introduction to the rules of the game
// returns false if the user lost, otherwise, returns true
bool tutorial();

// Default combat, takes 2 dialogues to be displayed during the combats
// The first one is displayed at the beginning of the combat
// The second one, when the cards are shown
// returns false if the user lost, otherwise, returns true
bool combat(const char *, const char *);
