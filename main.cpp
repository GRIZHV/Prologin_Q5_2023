//
//  main.cpp
//  Prologin-Qualif-5-2023
//
//  Created by William Koskas de Diego on 26/01/2023.
//

#include <iostream>
#include <algorithm>
using namespace std;

long int ValeurMax(int NbAccroche, int MaxNbGroupe, long int *Score)
{
  long int *ScorePrecedent = new long int[NbAccroche + 1];
  long int *ScoreActuel = new long int[NbAccroche];
  for (int i = 0; i < NbAccroche + 1; i++)
    ScorePrecedent[i] = 0;
  for (int i = 0; i < NbAccroche; i++)
    ScoreActuel[i] = 0;
  long int ScoreRecord=0;
  for (int NbG = 1; NbG < MaxNbGroupe + 1; NbG++)
  {
    for (int i=NbAccroche-4; i>=0; i--)
    {
      if(Score[i] + ScorePrecedent[i+4]> ScoreActuel[i+1])
        ScoreActuel[i] = Score[i] + ScorePrecedent[i+4];
      else
        ScoreActuel[i]=ScoreActuel[i+1];
    }
    bool MemeLigne = true;
    for (int i = 0; i < NbAccroche - 3; i++)
      if (ScoreActuel[i] != ScorePrecedent[i])
      {
        MemeLigne = false;
        break;
      }
    if (MemeLigne)
      break;
    for (int i=0; i<NbAccroche-3; i++)
      ScorePrecedent[i]=ScoreActuel[i];
  }
  ScoreRecord = ScoreActuel[0];
  delete[] ScorePrecedent;
  delete[] ScoreActuel;
  return ScoreRecord;
}

int main()
{
  int NbAccroche, NbStabilisateur, IndiceStabilite;
  cin >> NbAccroche >> NbStabilisateur >> IndiceStabilite;
  int *Accroches = new int[NbAccroche];
  long int *Score = new long int[NbAccroche];
  for (int i=0; i<NbAccroche; i++)
    cin >> Accroches[i];
  sort(Accroches, Accroches+NbAccroche);
  for (int i=0; i<NbAccroche-3; i++)
    Score[i] = IndiceStabilite-((long int)(Accroches[i+3]-Accroches[i]))*(Accroches[i+3]-Accroches[i]);
  long int ScoreRecord = 0;
  ScoreRecord = ValeurMax(NbAccroche, NbStabilisateur, Score);
  cout << ScoreRecord;
  delete[] Accroches;
  delete[] Score;
  return 0;
}
