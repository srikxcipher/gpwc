#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML/Audio.hpp>
using namespace sf;
enum class side
{
    LEFT,
    RIGHT,
    NONE
};
const int NUM_BRANCHES = 6;
side branchPositions[NUM_BRANCHES];

void updateBranches(int);

void updateBranches(int seed)
{
    for (int j = NUM_BRANCHES - 1; j > 0; j--)
    {
        branchPositions[j] = branchPositions[j - 1];
    }
    srand((int)time(0) + seed);
    int r = rand() % 5; // 0,1,2,3,4
    switch (r)
    {
    case 0:
        branchPositions[0] = side::LEFT;
        break;

    case 1:
        branchPositions[0] = side::RIGHT;
        break;

    default:
        branchPositions[0] = side::NONE;
    } // end - switch

} // func ends.

int main()
{

    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber Game!!!", Style::Fullscreen); //, Style::Fullscreen
    // -------------------------------------------------- //
    Texture textureBackground; // obj of class Texture
    textureBackground.loadFromFile("res/graphics/background.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);
    // -------------------------------------------------- //
    Texture textureTree;
    textureTree.loadFromFile("res/graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);
    // -------------------------------------------------- //
    Texture textureCloud;
    textureCloud.loadFromFile("res/graphics/cloud.png");
    Sprite spriteCloud;
    spriteCloud.setTexture(textureCloud);
    spriteCloud.setPosition(0, 0);
    // -------------------------------------------------- //
    // Texture textureCloud2;
    Sprite spriteCloud2;
    spriteCloud2.setTexture(textureCloud);
    spriteCloud2.setPosition(400, 250);
    // -------------------------------------------------- //
    // Texture textureCloud3;
    Sprite spriteCloud3;
    spriteCloud3.setTexture(textureCloud);
    spriteCloud3.setPosition(1200, 0);
    // -------------------------------------------------- //
    Texture textureBee;
    textureBee.loadFromFile("res/graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);
    // -------------------------------------------------- //
    Sprite spriteBee2;
    spriteBee2.setTexture(textureBee);
    spriteBee2.setPosition(0, 900);

    // -------------------------------------------------- //
    Texture textureBranch;
    textureBranch.loadFromFile("res/graphics/branch.png");
    Sprite spriteBranches[6];
    for (int i = 0; i < NUM_BRANCHES; i++)
    {
        spriteBranches[i].setTexture(textureBranch);
        spriteBranches[i].setPosition(-2000, -2000);
        spriteBranches[i].setOrigin(220, 20);
    }
    // -------------------------------------------------- //
    // PLAYER//
    // -------------------------------------------------- //
    Texture texturePlayer;
    texturePlayer.loadFromFile("res/graphics/player.png");
    Sprite spritePlayer;
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setPosition(580, 720);
    side PlayerSide = side::LEFT;

    // -------------------------------------------------- //
    // AXE//
    // -------------------------------------------------- //
    Texture textureAxe;
    textureAxe.loadFromFile("res/graphics/axe.png");
    Sprite spriteAxe;
    spriteAxe.setTexture(textureAxe);
    spriteAxe.setPosition(700, 830);
    const float AXE_POSITION_LEFT = 700;
    const float AXE_POSITION_RIGHT = 1075;

    // -------------------------------------------------- //
    // RIP//
    // -------------------------------------------------- //
    Texture textureRip;
    textureRip.loadFromFile("res/graphics/rip.png");
    Sprite spriteRip;
    spriteRip.setTexture(textureRip);
    spriteRip.setPosition(600, 860);
    // -------------------------------------------------- //
    // LOG//
    // -------------------------------------------------- //
    Texture textureLog;
    textureLog.loadFromFile("res/graphics/log.png");
    Sprite spriteLog;
    spriteLog.setTexture(textureLog);
    spriteLog.setPosition(810, 720);
    bool logActive = false;
    float logSpeedX = 1000;
    float logSpeedY = -1500;
    // -------------------------------------------------- //

    Font font;
    font.loadFromFile("res/font/KOMIKAP_.ttf");

    Text messageText;
    messageText.setFont(font);
    messageText.setString("Enter to Start!!!");
    messageText.setCharacterSize(80);
    messageText.setFillColor(Color::White);

    // --------------------To display text in center--------------------- //

    messageText.setPosition(1920 / 2, 1080 / 2);
    FloatRect rect = messageText.getLocalBounds();
    messageText.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);

    // -------------------------------------------------- //

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: 0");
    scoreText.setCharacterSize(100);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(20, 20);

    bool beeActive = false;

    float beeSpeed = 0.0f;

    bool cloud1Active = false;

    float cloud1Speed = 0.0f;

    bool cloud2Active = false;

    float cloud2Speed = 0.0f;

    bool cloud3Active = false;

    float cloud3Speed = 0.0f;

    bool acceptInput = false;

    Clock clock;

    bool paused = true;
    int score = 0;

    RectangleShape timeBar;
    float timeBarStartWidth = 100;
    float timeBarHeight = 80;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setPosition(1920 / 2.0 - timeBarStartWidth / 2.0, 980);
    timeBar.setFillColor(Color::Red);

    float timeRemaining = 6.0f;
    float timeBarStartWidthPerSec = timeBarStartWidth / timeRemaining;

    // updateBranches(1);
    // updateBranches(2);
    // updateBranches(3);
    // updateBranches(4);
    // updateBranches(5);

    // -------------------------------------------------- //

    // Game Sounds

    SoundBuffer deathBuffer;
    deathBuffer.loadFromFile("res/sound/death.wav");
    Sound death;
    death.setBuffer(deathBuffer);
    // ------------------------------------------------- //
    SoundBuffer chopBuffer;
    chopBuffer.loadFromFile("res/sound/chop.wav");
    Sound chop;
    chop.setBuffer(chopBuffer);
    // ------------------------------------------------- //
    SoundBuffer ootBuffer;
    ootBuffer.loadFromFile("res/sound/out_of_time.wav");
    Sound oot;
    oot.setBuffer(ootBuffer);

    // Main GameLoop
    while (window.isOpen())
    {

        // To handle the window close pop-up
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyReleased && !paused)
            {
                // Listen for key presses again
                acceptInput = true;
                spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Return))
        {
            paused = false;
            score = 0;
            timeRemaining = 6.0f;
            for (int i = 0; i < NUM_BRANCHES; i++)
            {
                branchPositions[i] = side::NONE;
            }
            spritePlayer.setPosition(580, 720);
            spriteRip.setPosition(680, 2000); // RIP Hidden
            acceptInput = true;
        }
        if (acceptInput)
        {
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                PlayerSide = side::RIGHT;
                score = score + 1;
                timeRemaining = timeRemaining + 0.15 + 2 / score;
                spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);
                spritePlayer.setPosition(1200, 720);
                updateBranches(score);
                spriteLog.setPosition(810, 720);
                logSpeedX = -5000;
                logActive = true;
                acceptInput = false;
                //--------------chop.wav-----------------//
                chop.play();
            }
            if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                PlayerSide = side::LEFT;
                score = score + 1;
                timeRemaining = timeRemaining + 0.15 + 2 / score;
                spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);
                spritePlayer.setPosition(580, 720);
                updateBranches(score);
                spriteLog.setPosition(810, 720);
                logSpeedY = 5000;
                logActive = true;
                acceptInput = false;
                //--------------chop.wav-----------------//
                chop.play();
            }
        }

        // -------------------------------------------------- //
        

        if (!paused)
        {
            Time dt = clock.restart();

            timeRemaining = timeRemaining - dt.asSeconds();
            timeBar.setSize(Vector2f(timeBarStartWidthPerSec * timeRemaining, timeBarHeight));

            // End of time remaining
            if (timeRemaining <= 0.0f)
            {
                paused = true;
                messageText.setString("Out of time!!!");
                //---------------out_of_time.wav--------------------//
                oot.play();

                messageText.setFillColor(Color::White);
                FloatRect rect = messageText.getLocalBounds();
                messageText.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
            }

            if (!beeActive)
            {
                srand((int)time(0));
                beeSpeed = rand() % 200 + 200;
                srand((int)time(0));
                float height = rand() % 1350 + 500;
                spriteBee.setPosition(1950, height);
                beeActive = true;
            }
            else
            {
                spriteBee.setPosition(spriteBee.getPosition().x -
                                          beeSpeed * dt.asSeconds(),
                                      spriteBee.getPosition().y);
                if (spriteBee.getPosition().x < -10)
                {
                    beeActive = false;
                }
            }

            // Cloud movement logic
            if (!cloud1Active)
            {
                srand((int)time(0) * 10);
                cloud1Speed = rand() % 80;
                srand((int)time(0) * 10);
                float height = rand() % 150;
                spriteCloud.setPosition(-400, height);
                cloud1Active = true;
            }

            else
            {
                spriteCloud.setPosition(spriteCloud.getPosition().x +
                                            cloud1Speed * dt.asSeconds(),
                                        spriteCloud.getPosition().y);
                if (spriteCloud.getPosition().x > 1920)
                {
                    cloud1Active = false;
                }
            }

            // Cloud-2 movement logic
            if (!cloud2Active)
            {
                srand((int)time(0) * 10);
                cloud2Speed = rand() % 200;
                srand((int)time(0) * 10);
                float height = rand() % 100;
                spriteCloud2.setPosition(-300, height);
                cloud2Active = true;
            }

            else
            {
                spriteCloud2.setPosition(spriteCloud2.getPosition().x +
                                             cloud2Speed * dt.asSeconds(),
                                         spriteCloud2.getPosition().y);
                if (spriteCloud2.getPosition().x > 1920)
                {
                    cloud2Active = false;
                }
            }

            // Cloud-3 movement logic
            if (!cloud3Active)
            {
                srand((int)time(0) * 20);
                cloud3Speed = rand() % 150;
                srand((int)time(0) * 10);
                float height = rand() % 100;
                spriteCloud3.setPosition(-300, height);
                cloud3Active = true;
            }

            else
            {
                spriteCloud3.setPosition(spriteCloud3.getPosition().x +
                                             cloud3Speed * dt.asSeconds(),
                                         spriteCloud3.getPosition().y);
                if (spriteCloud3.getPosition().x > 1920)
                {
                    cloud3Active = false;
                }
            }

            // Score Increment
            // score++;
            //  Updating the Score
            std::stringstream ss;
            ss << "Score = " << score;
            scoreText.setString(ss.str());

            // Update Branches

            for (int i = 0; i < NUM_BRANCHES; i++)
            {
                float height = i * 150;
                if (branchPositions[i] == side::LEFT)
                {
                    spriteBranches[i].setPosition(610, height);
                    spriteBranches[i].setRotation(180);
                }
                else if (branchPositions[i] == side::RIGHT)
                {
                    spriteBranches[i].setPosition(1330, height);
                    spriteBranches[i].setRotation(0);
                }
                else
                {
                    spriteBranches[i].setPosition(3000, height);
                }

            } // end of Update

            if (logActive)
            {
                spriteLog.setPosition(spriteLog.getPosition().x + logSpeedX * dt.asSeconds(),
                                      spriteLog.getPosition().y + logSpeedY * dt.asSeconds());

                if (spriteLog.getPosition().x > 2000 || spriteLog.getPosition().x < 100)
                {
                    logActive = false;
                    spriteLog.setPosition(800, 600);
                }
            } // end - of logActive

            // Handles Player's Death
            if (branchPositions[5] == PlayerSide)
            {
                paused = true;
                acceptInput = false;
                // Hide the Player!
                spritePlayer.setPosition(2000, 720);
                // Set RIP
                spriteRip.setPosition(525, 760);
                // Set Axe
                spriteAxe.setPosition(2000, 720);
                // Text Msg - Game Over!
                messageText.setString("Sqished!!!");
                messageText.setFillColor(Color::White);
                messageText.setPosition(1920 / 2, 1080 / 2);
                FloatRect rect = messageText.getLocalBounds();
                messageText.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
                //--------------------------death.wav---------------------------------//
                death.play();

            } // End of Players - Death

        } // end - of paused!

        window.clear();
        window.draw(spriteBackground);
        window.draw(spriteTree);
        for (int i = 0; i < NUM_BRANCHES; i++)
        {
            window.draw(spriteBranches[i]);
        }
        window.draw(spriteCloud);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        if (paused)
        {
            window.draw(messageText);
        }

        window.draw(scoreText);
        window.draw(spriteBee);
        window.draw(timeBar);
        window.draw(spriteLog);
        window.draw(spriteRip);
        window.draw(spriteAxe);
        window.draw(spritePlayer);

        // window.draw(spriteBee2);
        window.display();
    } // end of while()
    return 0;
}
