# The Galactic War

Marica Mihai
312CA


Am început problema prin a declara variabilele, a le citi și a le aloca
dinamic pe cele necesare.

Task 1

În variabila "n" am adunat valorile octeților de pe prima
linie, ultima linie și marginile laterale ale hărții. În același timp, am
calculat numărul de bytes poziționați pe marginea hărții, mărind variabila
"p". Împărțind valorile celor două variabile, am aflat media aritmetică a
octeților de pe conturul hărții, adică gradul de încărcare al scutului
protector, pe care am și afișat-o.

Task 2

Am corectat harta de la Task-ul 1, realizând operațiile de Modify,
Delete și Swap asupra blocurilor de date de tip char, short int, respectiv int.
Pentru instrucțiunea Modify de int, valoarea citită de la tastatură a fost
înlocuită direct cu cea din matrice, iar pentru celelalte, am înlocuit valoarea
octeților din matrice, în funcție de tipul de dată citită și tipul de operație.

Task 3

Am prelucrat algoritmul fill conform cerinței date, pe care l-am
aplicat astfel: am căutat elementele egale cu "0" ale matricii date, iar atunci
când le-am găsit, le-am dat valoarea "1", pornind, de asemenea, algoritmul
fill. Pentru a nu verifica aceleași elemente în mod repetat, după terminarea
algoritmului, toți termenii găsiți în algoritm și egali cu "0" au fost
transformați în "1". Am selectat astfel cea mai lungă secvență de zerouri,
afisandu-i termenul situat pe cea mai mică poziție și lungimea sa.

În final, am eliberat memoria alocată inițial.
