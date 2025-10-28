# GW-projekt-Cpp-zaliczenie

Założenie:
Aplikacja quizowa działająca w terminalu (jeżeli nie polegnę, to z chęcią zrobię to w aplikacji okienkowej). Użytkownik zaczyna grę w menu, z którego może wybrać jedną z trzech opcji: rozpoczęcie gry, sprawdzenie rankingu lub wyjście. Po wybraniu pierwszej opcji, zostaje zapytany o zakres liczb oraz typ działań matematycznych (+, -, *, / - można wybrać dowolne, ale przynajmniej jeden typ musi zostać zaznaczony). Następnie gracz odpowiada na losowo generowane pytania z czterema odpowiedziami (A–D) w losowej kolejności do x pomyłek (każdy gracz ograniczoną liczbę żyć na jedną turę). Po zakończeniu gry, jeśli liczba uzyskanych punktów przez gracza mieści się w rankingu, gra informuje o dobrym wyniku, pyta go o nick oraz zapisuje do pliku ranking.txt. Jeżeli gracz wybierze opcję "ranking" w menu, to wyświetla mu się ranking np. 10 najlepszych wyników. Po wybraniu opcji "wyjście" w menu, gra oczywiście kończy się.

Osiągnięte:
Aplikacja działa w konsoli. Są trzy opcje do wybrania:
  1. Rozpocznij grę:
     
    - gracz wybiera zakres działań (liczbę) oraz typy działań (+, -, *, /),
    
    - odpowiedzi są podawane w formie wyboru A B C D (trzy złe, jedna dobra),
    
    - każdy gracz ma 3 życia i może grać w nieskończoność,
    
    - za każde dobrze rozwiązane działanie gracz otrzymuje 1 punkt,
    
    - po skończeniu gry, można wpisać się do rankingu.
    
  3. Zobacz ranking:
     
    - pokazuje ranking 10 najlepszych wyników.
    
  5. Wyjście.
