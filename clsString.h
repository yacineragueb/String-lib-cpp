#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsString
{
private:
	string _Value;

public:

	clsString() {
		_Value = "";
	}

	clsString(string Value) {
		_Value = Value;
	}

	void setValue(string Value) {
		_Value = Value;
	}

	string GetValue() {
		return _Value;
	}

	__declspec(property(get = GetValue, put = setValue)) string Value;

	static short Length(string String) {
		return String.length();
	}

	short Length() {
		return _Value.length();
	}

	static void GetFirstLetters(string& sentence)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] != ' ' && isFirstLetter)
			{
				cout << sentence[i] << endl;
			}

			isFirstLetter = sentence[i] == ' ' ? true : false;
		}
	}

	void GetFirstLetters() {
		GetFirstLetters(_Value);
	}

	static string UppercaseFirstLetters(string sentence)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] != ' ' && isFirstLetter)
			{
				sentence[i] = char(toupper(sentence[i]));
			}

			isFirstLetter = sentence[i] == ' ' ? true : false;
		}

		return sentence;
	}

	void UppercaseFirstLetters() {
		// No need to return value, this function will directly update the object value.
		_Value =  UppercaseFirstLetters(_Value);
	}

	static string LowercaseFirstLetters(string sentence)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] != ' ' && isFirstLetter)
			{
				sentence[i] = tolower(sentence[i]);
			}

			isFirstLetter = sentence[i] == ' ' ? true : false;
		}

		return sentence;
	}

	void LowercaseFirstLetters() {
		_Value = LowercaseFirstLetters(_Value);
	}

	static string UpperAllString(string sentence)
	{

		for (int i = 0; i < sentence.length(); i++)
		{
			sentence[i] = toupper(sentence[i]);
		}

		return sentence;
	}

	void UpperAllString() {
		_Value =  UpperAllString(_Value);
	}

	static string LowerAllString(string sentence)
	{

		for (int i = 0; i < sentence.length(); i++)
		{
			sentence[i] = tolower(sentence[i]);
		}

		return sentence;
	}

	void LowerAllString() {
		_Value = LowerAllString(_Value);
	}

	static char InverteLettercase(char character)
	{
		return isupper(character) ? tolower(character) : toupper(character);
	}

	static string InverteAllLettersCase(string sentence)
	{

		for (int i = 0; i < sentence.length(); i++)
		{
			sentence[i] = InverteLettercase(sentence[i]);
		}

		return sentence;
	}

	void InverteAllLettersCase() {
		_Value = InverteAllLettersCase(_Value);
	}

	static short CountCapitalLetters(string sentence)
	{
		short count = 0;

		for (int i = 0; i < sentence.length(); i++)
		{
			if (isupper(sentence[i]))
				count++;
		}

		return count;
	}

	short CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string sentence)
	{
		short count = 0;

		for (int i = 0; i < sentence.length(); i++)
		{
			if (islower(sentence[i]))
				count++;
		}

		return count;
	}

	short CountSmallLetters() {
		return CountSmallLetters(_Value);
	}

	enum enWhatToCount
	{
		SmallLetters = 0,
		CapitalLetters = 1,
		All = 3
	};

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{

		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;

			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;
		}

		return Counter;
	}

	static short CountSpecificLetter(string sentence, char characterToSearch, bool MatchCase = true)
	{
		short count = 0;

		for (int i = 0; i < sentence.length(); i++)
		{

			if (MatchCase)
			{
				if (sentence[i] == characterToSearch)
					count++;
			}
			else
			{
				if (tolower(sentence[i]) == tolower(characterToSearch))
					count++;
			}
		}

		return count;
	}

	short CountSpecificLetter(char characterToSearch, bool MatchCase = true) {
		return CountSpecificLetter(_Value, characterToSearch, MatchCase);
	}

	static bool IsVowelLetter(char character)
	{
		char Char1 = tolower(character);
		return ((Char1 == 'a') || (Char1 == 'e') || (Char1 == 'i') || (Char1 == 'o') || (Char1 == 'u'));
	}

	static short CountVowelsLetter(string sentence)
	{
		short count = 0;
		for (int i = 0; i < sentence.length(); i++)
		{
			if (IsVowelLetter(sentence[i]))
				count++;
		}

		return count;
	}

	short CountVowelsLetter() {
		return CountVowelsLetter(_Value);
	}

	static short CountWords(string sentence)
	{
		string delim = " ";
		short pos = 0, count = 0;
		string sWord;

		while ((pos = sentence.find(delim)) != std::string::npos)
		{
			sWord = sentence.substr(0, pos);
			if (sWord != "")
			{
				count++;
			}

			sentence.erase(0, pos + delim.length());
		}

		if (sentence != "")
		{
			count++;
		}

		return count;
	}

	short CountWords() {
		return CountWords(_Value);
	}

	static vector<string> Split(string sentence, string delim)
	{
		vector<string> vWords;
		short pos;
		string word;

		while ((pos = sentence.find(delim)) != std::string::npos)
		{
			word = sentence.substr(0, pos);

			if (word != "")
			{
				vWords.push_back(word);
			}

			sentence.erase(0, pos + delim.length());
		}

		if (sentence != "")
		{
			vWords.push_back(sentence);
		}

		return vWords;
	}

	vector<string> Split(string delim) {
		return Split(_Value, delim);
	}

	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight() {
		_Value = TrimRight(_Value);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}

	void Trim() {
		_Value = Trim(_Value);
	}

	static string Join(vector<string> vWords, string separator)
	{
		string sentence = "";

		for (string& word : vWords)
		{

			sentence += word + separator;
		}

		return sentence.substr(0, sentence.length() - separator.length());
	}

	static string Join(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReverseWordsInString(string sentence)
	{
		vector<string> vWords = Split(sentence, " ");
		vector<string> vReverseWords;

		while (!vWords.empty())
		{
			string lastWord = vWords.back();
			vReverseWords.push_back(lastWord);
			vWords.pop_back();
		}

		string ReverseSentence = Join(vReverseWords, " ");

		return ReverseSentence;
	}

	void ReverseWordsInString() {
		_Value = ReverseWordsInString(_Value);
	}

	static string Replace(string sentence, string WordToReplace, string ReplaceWith, bool Matchcase = true)
	{
		vector<string> vWords = Split(sentence, " ");

		for (string& word : vWords)
		{
			if (Matchcase)
			{
				if (word == WordToReplace)
				{
					word = ReplaceWith;
				}
			}
			else
			{
				if (LowerAllString(word) == LowerAllString(WordToReplace))
				{
					word = ReplaceWith;
				}
			}
		}

		sentence = Join(vWords, " ");

		return sentence;
	}

	void Replace(string StringToReplace, string sReplaceTo, bool Matchcase = true) {
		_Value =  Replace(_Value, StringToReplace, sReplaceTo, Matchcase);
	}

	static string RemovePunctuations(string sentence)
	{
		string S2 = "";

		for (int i = 0; i < sentence.length(); i++)
		{
			if (!ispunct(sentence[i]))
			{
				S2 += sentence[i];
			}
		}

		return S2;
	}

	void RemovePunctuations() {
		_Value = RemovePunctuations(_Value);
	}
};

