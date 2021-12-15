
int Randomgenerator()
{
	char Questions[];
	int RandomNr;
	char Quest;


	string Frage_1 = "I am over powered";
	string Frage_2 = "Lost in space";
	string Frage_3 = "cracked up";



	Questions[0] = rand() % 10 + 1;

	do(
		RandomNr = rand() % 10 + 1;
		int index = Array.IndexOf(Questions, RandomNr)
	)
	while(index == -1)
		
	Questions[1] = RandomNr

	do(
		RandomNr = rand() % 10 + 1;
		int index = Array.IndexOf(Questions, RandomNr)
	)
	while(index == -1)
		
	Questions[2] = RandomNr

	do(
		RandomNr = rand() % 10 + 1;
		int index = Array.IndexOf(Questions, RandomNr)
	)
	while(index == -1)
		
	Questions[3] = RandomNr

	do(
		RandomNr = rand() % 10 + 1;
		int index = Array.IndexOf(Questions, RandomNr)
	)
	while(index == -1)
		
	Questions[4] = RandomNr



	for (i = 0; i < Questions.size(); i++) 
	{
		Questions[i] = "Frage_%f \n", Questions[i];
		Quest = printf("%s \n" ,Questions[i])  
		printf("%s \n" ,Quest)
	}
}
