mkdir bin
cd src
g++ main.cpp LTexture.cpp ActorComponents.cpp Actor.cpp -lSDL2 -lSDL2_image -o ../bin/Equasion &&
echo "Compilation successful."
