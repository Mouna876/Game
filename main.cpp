#include<SFML/Graphics.hpp>
#include<time.h>
using namespace sf;
int main(){
	RenderWindow app(VideoMode(520,450),"Arkanoid Game!");
	app.setFramerateLimit(30);
	
	Texture t1,t2,t3,t4;
	t1.loadFromFile("images/block04.png");
	t2.loadFromFile("images/backround.jpg");
	t3.loadFromFile("images/ball.png");
	t4.loadFromFile("images/paddle.png");
	Sprite sBackground(t2), sBall(t3), sPaddle(t4);
	sPaddle.setPosition(300,440);
	sBall.setPosition(300,440);
	Sprite bloc [1000];
	int n=0;
	for(int i=1;i<=10;i++) 
	for(int j=1;j<=10;j++)
	{
		bloc[n].setTexture(t1);
		bloc[n].setPosition(i*43,j*20);
		n++;
	 } 
	  float  dx=6 , dy=5;
	while (app.isOpen())
	{
		Event e ;
		while (app.pollEvent(e))
		{
			if ( e.type == Event::Closed)
			app.close();
		}
		sBall.move(dx,dy);
		Vector2f b = sBall.getPosition(); 
		if(b.x<0 || b.x>520) dx=-dx;
		if(b.x<0 || b.x>450) dx=-dx;
		app.clear();
		app.draw(sBackground);
		app.draw(sBall);
		app.draw(sPaddle);
		for ( int i=0 ; i<n ; i++)
		app.draw(bloc[i]);
		app.display();
	}
	return 0;
} 
