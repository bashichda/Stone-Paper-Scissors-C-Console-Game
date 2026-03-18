// Project 1 Stone-Paper-Scissor : 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enPlayerChoice { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stGameResults
{
	short PlayerWonTimes = 0;
	short ComputerWonTimes = 0;
	short DrawTimes = 0;
	short GameRounds = 0;
	enWinner Winner = enWinner::Computer;
};

int RandomNumber(int From, int To) {

	//Function To Generate a random Number :
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}


short ReadHowManyRounds() {

	short Rounds = 0;
	
	do
	{
	cout << "How Many Rounds From 1 To 10 : ";
	cin >> Rounds;
	} while (Rounds < 1 || Rounds > 10);

	return Rounds;
}

enPlayerChoice ReadPlayerChoice() {

	short Choice = 0;

	cout << "\nYour Choice : [1]:Stone, [2]:Paper,[3]:Scissors : \n";
	cin >> Choice;

	while (Choice < 1 || Choice > 3) {

		cout << "\nInvalid Input !\n";
		cout << "\nYour Choice : [1]:Stone, [2]:Paper,[3]:Scissors : \n";
		cin >> Choice;
	}

	return enPlayerChoice(Choice);
}

enPlayerChoice GetComputerChoice() {

	short Choice = RandomNumber(1, 3);

	return enPlayerChoice(Choice);
}

void AddWinnerInTotalResult(enWinner Winner,stGameResults &GameResult) {

	switch (Winner) {
	case enWinner::Player:
		GameResult.PlayerWonTimes++;
		break;
	case enWinner::Computer:
		GameResult.ComputerWonTimes++;
		break;
	case enWinner::Draw:
		GameResult.DrawTimes++;
		break;
	default:
		break;
	}
}

void WinnerBagroundEffect(enWinner Winner) {
	
	switch (Winner) {
	case enWinner::Player:
		system("color 2F");
		break;
	case enWinner::Computer:
		system("color 4F");
		break;
	case enWinner::Draw:
		system("color 6F");
		break;
	default:
		system("color 0F");
	}
}

enWinner CheckWinnerInRound(enPlayerChoice PlayerChoice, enPlayerChoice ComputerChoice) {

	if ((PlayerChoice == enPlayerChoice::Stone && ComputerChoice == enPlayerChoice::Scissors) ||
		(PlayerChoice == enPlayerChoice::Paper && ComputerChoice == enPlayerChoice::Stone) ||
		(PlayerChoice == enPlayerChoice::Scissors && ComputerChoice == enPlayerChoice::Paper)) {
		return enWinner::Player;
	}
	else if ((ComputerChoice == enPlayerChoice::Stone && PlayerChoice == enPlayerChoice::Scissors) ||
		(ComputerChoice == enPlayerChoice::Paper && PlayerChoice == enPlayerChoice::Stone) ||
		(ComputerChoice == enPlayerChoice::Scissors && PlayerChoice == enPlayerChoice::Paper)){
		return enWinner::Computer;
	}
	else {
		return enWinner::Draw;
	}

}

string GetChoiceName(enPlayerChoice Choice) {

	switch (Choice) {
	case enPlayerChoice::Stone:
		return "Stone";
	case enPlayerChoice::Paper:
		return "Paper";
	case enPlayerChoice::Scissors:
		return "Scissors";
	default:
		return "Error 404";
	}
}

string GetWinnerName(enWinner Winner) {
	switch (Winner) {
	case enWinner::Player:
		return "Player";
	case enWinner::Computer:
		return "Computer";
	case enWinner::Draw:
		return "No Winner";
	default:
		return "Error 404";
	}
}

void ShowRoundResult(stGameResults &GameResult,short RoundNumber, enPlayerChoice PlayerChoice, enPlayerChoice ComputerChoice) {

	enWinner RoundWinner =  CheckWinnerInRound(PlayerChoice, ComputerChoice);
	WinnerBagroundEffect(RoundWinner);
	AddWinnerInTotalResult(RoundWinner,GameResult);

	cout << "\n________________Round [" << RoundNumber << "]________________" << endl;
	cout << "\nPlayer1 Choice : " << GetChoiceName(PlayerChoice);
	cout << "\nComputer Choice : " << GetChoiceName(ComputerChoice);
	cout << "\nRound Winner : " << " [" << GetWinnerName(RoundWinner) << "] ";
	cout << "\n________________________________________" << endl;
}

void GameOverScreen() {

	cout << "\n\t\t________________________________________________________\n";
	cout << "\n\t\t\t\t+++ G a m e  O v e r +++ ";
	cout << "\n\t\t________________________________________________________\n";

}

void ShowFinalResult(stGameResults GameResult) {

	WinnerBagroundEffect(GameResult.Winner);

	cout << "\n\t\t____________________ [ Game Results ] __________________\n";
	cout << "\n\t\tGame Rounds        : " << GameResult.GameRounds;
	cout << "\n\t\tPlayer won times   : " << GameResult.PlayerWonTimes;
	cout << "\n\t\tComputer won times : " << GameResult.ComputerWonTimes;
	cout << "\n\t\tDraw Times         : " << GameResult.DrawTimes;
	cout << "\n\t\tFinal Winner       : " << GetWinnerName(GameResult.Winner);
	cout << "\n\t\t________________________________________________________\n";

}

enWinner GetTheFinalWinner(stGameResults GameResult) {

	if (GameResult.PlayerWonTimes > GameResult.ComputerWonTimes)
		return enWinner::Player;
	else if (GameResult.ComputerWonTimes > GameResult.PlayerWonTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

void PlayGameRounds() {

	stGameResults GameResult;
	GameResult.GameRounds = ReadHowManyRounds();

	for (short i = 0; i < GameResult.GameRounds; i++)
	{
		cout << "\nRound [" << i + 1 << "] begins: \n";
		ShowRoundResult(GameResult,i + 1, ReadPlayerChoice(), GetComputerChoice());
	}
	GameResult.Winner = GetTheFinalWinner(GameResult);
	GameOverScreen();
	ShowFinalResult(GameResult);
}

void StartGame() {
	
	char AddMore = 'y';

	do
	{
		system("color 0F");
		system("cls");
		PlayGameRounds();
		
		cout << "\n\t\tDo you want to Play Again ? Y | N : ";
		cin >> AddMore;

	} while (AddMore == 'y' || AddMore == 'Y');
}

int main() {

	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
