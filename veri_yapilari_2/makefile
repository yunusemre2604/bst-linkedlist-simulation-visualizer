hepsi:derle calistir

# Derleme işlemi icin
derle: 	
	g++ -I ./include/ -o ./lib/Karakter.o -c ./src/Karakter.cpp
	g++ -I ./include/ -o ./lib/IkiliAramaAgaci.o -c ./src/IkiliAramaAgaci.cpp
	g++ -I ./include/ -o ./lib/BagliListe.o -c ./src/BagliListe.cpp
	g++ -I ./include/ -o ./bin/Program ./lib/Karakter.o ./lib/IkiliAramaAgaci.o ./lib/BagliListe.o ./src/main.cpp

# Programı calistirmak icin
calistir:
	./bin/Program

