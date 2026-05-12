//game.cpp
#include "game.h"
#include "UImanager.h"

int clickedIndex;
bool blenderopen = false;
Game::Game(RenderWindow& win)
    : window(win),
    pizza(),
    olives("assets/pizza/olive-.png", { 30, 550 }),
    cheese("assets/pizza/cheese--.png", { 540, 540 }),
    sausage("assets/pizza/sausage-.png", { 670, 550 }),
    mushrooms("assets/pizza/mushroom-.png", { 160, 545 }),
    pepperoni("assets/pizza/pep--.png", { 420, 550 }),
    onions("assets/salad/onion--.png", { 270, 538 }),
    onions2("assets/salad/onion--.png", { 265, 538 }),
    cucumber("assets/salad/cucumber--.png", { 545, 538 }),
    tomatoes("assets/salad/tomato.png", { 145, 545 }),
    chicken("assets/pizza/chicken.png", { 670, 545 }),
    lettuce("assets/salad/lettuce-.png", { 30, 550 }),
    olives2("assets/salad/olive---.png", { 420, 550 }),//c2
    banana("assets/milkshake/bananas.png", { 5, 550 }),
    strawberry("assets/milkshake/strawberry.png", { 135, 545 }),
    mangoes("assets/milkshake/mangoes.png", { 265, 540 }),
    vanicecream("assets/milkshake/vanicecream.png", { 395, 550 }),
    chocolateicecream("assets/milkshake/chocolateicecream.png", { 515, 550 }),
    tutifrutiicecream("assets/milkshake/tutifrutiicecream.png", { 650, 550 })

{
    state = gamestate::HOMEPAGE;

    // Load font
    if (!font.loadFromFile("assets/font/hot-pizza.normal.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }
    //add buttons
    uimanager.addbutton(Button({ 200, 60 }, { 120, 20 }, "Easy", font));
    uimanager.addbutton(Button({ 200, 60 }, { 500, 20 }, "Difficult", font));

    // Load textures
    if (!orderBgTex.loadFromFile("assets/bgstates/order.png"))
        throw runtime_error("Failed to load: order.png");
    if (!cookingBgTex.loadFromFile("assets/bgstates/cooking station.png"))
        throw runtime_error("Failed to load: cooking station.png");
    if (!ovenBgTex.loadFromFile("assets/bgstates/oven.jpeg"))
        throw runtime_error("Failed to load: oven.jpeg");
    if (!homeBgTex.loadFromFile("assets/bgstates/outside.png"))
        throw runtime_error("Failed to load: outside.png");
    if (!saladbarTex.loadFromFile("assets/bgstates/salad bar.png"))
        throw runtime_error("Failed to load: salad bar.png");
    if (!ranchTex.loadFromFile("assets/salad/ranch.png"))
        throw runtime_error("Failed to load: ranch.png");
    if (!mustardTex.loadFromFile("assets/salad/mustard.png"))
        throw runtime_error("Failed to load: mustard.png");
    if (!milkshakeTex.loadFromFile("assets/bgstates/milkshakebar.jpeg"))
        throw runtime_error("Failed to load: milkshakebar.jpeg");
    if (!blenderTex.loadFromFile("assets/milkshake/blend.png"))
        throw runtime_error("Failed to load: blend.png");

    // Assign textures
    orderBackground.setTexture(orderBgTex);
    saladbarbackground.setTexture(saladbarTex);
    cookingBackground.setTexture(cookingBgTex);
    ovenBackground.setTexture(ovenBgTex);
    homeBackground.setTexture(homeBgTex);
    ranchbackground.setTexture(ranchTex);
    mustardbackground.setTexture(mustardTex);
    milkshakebackground.setTexture(milkshakeTex);
    blenderbackground.setTexture(blenderTex);

    // Scale sprites
    auto scaleToWindow = [&](sf::Sprite& sprite, sf::Texture& tex)
        {
            sf::Vector2u texSize = tex.getSize();
            float scaleX = 800.0f / texSize.x;
            float scaleY = 800.0f / texSize.y;
            sprite.setScale(scaleX, scaleY);
        };

    scaleToWindow(orderBackground, orderBgTex);
    scaleToWindow(cookingBackground, cookingBgTex);
    scaleToWindow(ovenBackground, ovenBgTex);
    scaleToWindow(homeBackground, homeBgTex);
    scaleToWindow(saladbarbackground, saladbarTex);
    scaleToWindow(milkshakebackground, milkshakeTex);
    scaleToWindow(blenderbackground, blenderTex);

    currentOrder = new Order(font);
    pizza.generateMatrix(800, 600);

    // Start background music
    audio.start("assets/audio/Mambo Italiano.ogg");

    // Intro box
    ghazaal.setFont(font);
    ghazaal.setCharacterSize(23);
    ghazaal.setOutlineThickness(1);
    ghazaal.setOutlineColor(Color::Red);
    ghazaal.setFillColor(sf::Color::Black);
    ghazaal.setPosition(350, 630);
    ghazaal.setString("Ghazaal\n25l-2004");

    muaaz.setFont(font);
    muaaz.setCharacterSize(23);
    muaaz.setOutlineThickness(1);
    muaaz.setOutlineColor(sf::Color::Red);
    muaaz.setFillColor(sf::Color::Black);
    muaaz.setPosition(150, 670);
    muaaz.setString("Muaaz\n25l-3087");

    shahbaz.setFont(font);
    shahbaz.setCharacterSize(23);
    shahbaz.setOutlineThickness(1);
    shahbaz.setOutlineColor(sf::Color::Red);
    shahbaz.setFillColor(sf::Color::Black);
    shahbaz.setPosition(590, 670);
    shahbaz.setString("Shahbaz\n25l-0006");

    cookingTimeText.setFont(font);
    cookingTimeText.setCharacterSize(30);
    cookingTimeText.setFillColor(sf::Color::White);
    cookingTimeText.setOutlineColor(sf::Color::Red);
    cookingTimeText.setOutlineThickness(1);
    cookingTimeText.setPosition(20, 750);

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(125, 225);

    resultLabel.setFont(font);
    resultLabel.setCharacterSize(40);
    resultLabel.setFillColor(sf::Color::Red);
    resultLabel.setOutlineColor(sf::Color::Black);
    resultLabel.setOutlineThickness(3);
    resultLabel.setPosition(75, 150);

    saladScoreText.setFont(font);
    saladScoreText.setCharacterSize(30);
    saladScoreText.setFillColor(sf::Color::Black);
    saladScoreText.setPosition(125, 225);

    saladResultLabel.setFont(font);
    saladResultLabel.setCharacterSize(40);
    saladResultLabel.setFillColor(sf::Color::Red);
    saladResultLabel.setOutlineColor(sf::Color::Black);
    saladResultLabel.setOutlineThickness(3);
    saladResultLabel.setPosition(75, 150);

    milkScoreText.setFont(font);
    milkScoreText.setCharacterSize(30);
    milkScoreText.setFillColor(sf::Color::Black);
    milkScoreText.setPosition(125, 225);

    milkResultLabel.setFont(font);
    milkResultLabel.setCharacterSize(40);
    milkResultLabel.setFillColor(sf::Color::Red);
    milkResultLabel.setOutlineColor(sf::Color::Black);
    milkResultLabel.setOutlineThickness(3);
    milkResultLabel.setPosition(75, 150);

    //clock frames
    for (int i = 0; i < 21; i++) {
        if (!clockTextures[i].loadFromFile("assets/time/clock" + to_string(i) + ".jpeg")) {
            cout << "Error loading clock" << i << ".jpeg" << endl;
        }
    }
    clockSprite.setTexture(clockTextures[0]);
    clockSprite.setPosition(570, 550);
    clockSprite.setScale(
        200.f / clockTextures[0].getSize().x,
        200.f / clockTextures[0].getSize().y
    );

    //result screen
    if (!resultTex.loadFromFile("assets/bgstates/result.png"))
        throw runtime_error("Failed to load: result.png");
    resultBackground.setTexture(resultTex);
    scaleToWindow(resultBackground, resultTex);
}

void Game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents()
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close();
        }

        uimanager.handleEvents(window, event, clickedIndex);

        if ((state == gamestate::ResultPizza_SCREEN ||
            state == gamestate::ResultSalad_SCREEN ||
            state == gamestate::ResultMilk_Screen) && clickedIndex == 0)
        {
            state = gamestate::HOMEPAGE;
            difficultMode = false;
            difficultRound = 0;
            firstOrderType = -1;
            Cscore = 0;
            uimanager.clearbutton();
            uimanager.addbutton(Button({ 200, 60 }, { 120, 20 }, "Easy", font));
            uimanager.addbutton(Button({ 200, 60 }, { 500, 20 }, "Difficult", font));
        }

        else if (state == gamestate::HOMEPAGE && clickedIndex == 0) {
            state = gamestate::ORDER_SCREEN;
            uimanager.clearbutton();
            uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
            uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
            uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
            currentOrder->generateRandom();
        }
        
        else if (state == gamestate::HOMEPAGE && clickedIndex == 1) 
        {
            waqt.restart();
            difficultMode = true;
            difficultRound = 0;
            state = gamestate::ORDER_SCREEN;
            uimanager.clearbutton();
            uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
            uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
            uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
            currentOrder->generateRandom();
            firstOrderType = currentOrder->getOrderType();
        }
        
        else if (state != gamestate::HOMEPAGE &&
            state != gamestate::ResultPizza_SCREEN &&
            state != gamestate::ResultSalad_SCREEN &&
            state != gamestate::ResultMilk_Screen &&
            clickedIndex == 0) {
            state = gamestate::ORDER_SCREEN;
            uimanager.clearbutton();
            uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
            uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
            uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
            currentOrder->generateRandom();
        }
        else if (clickedIndex == 1)
        {
            state = gamestate::COOKING_SCREEN;
            pizza.clearSaladIngredients();
            pizza.clearSaladNames();
            pizza.clearpizzaingredients();
            pizza.clearmilk();
            pizza.clearMilkNames();
            pizza.clearIngredientNames();
            uimanager.clearbutton();
            uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
            uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
            uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
        }
        else if (clickedIndex == 2)
        {
            state = gamestate::OVEN_SCREEN;
            pizza.clearSaladIngredients();
            pizza.clearSaladNames();
            pizza.clearpizzaingredients();
            pizza.clearmilk();
            pizza.clearMilkNames();
            uimanager.clearbutton();

            // reset clock every time oven screen is entered
            ovenRunning = false;
            currentClockFrame = 0;
            clockSprite.setTexture(clockTextures[0]);
            clockSprite.setScale(
                200.f / clockTextures[0].getSize().x,
                200.f / clockTextures[0].getSize().y
            );
            clockFrameTimer = 0.f;

            cookingTimeSeconds = 5 + rand() % 6;
            cookingTimeText.setString("Cooking time is: " + to_string(cookingTimeSeconds) + " seconds");

            uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
            uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
            uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
            uimanager.addbutton(Button({ 200, 60 }, { 20, 100 }, "Start", font));   // index 5
            uimanager.addbutton(Button({ 200, 60 }, { 20, 175 }, "Serve", font));   // index 6
        }
        else if (clickedIndex == 3)
        {
            state = gamestate::SALADBAR_SCREEN;
            pizza.clearSaladIngredients();
            pizza.clearSaladNames();
            pizza.clearpizzaingredients();
            pizza.clearmilk();
            pizza.clearMilkNames();
            uimanager.clearbutton();
            uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
            uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
            uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
            if (state == gamestate::SALADBAR_SCREEN && clickedIndex == 3)
            {
                uimanager.addbutton(Button({ 200, 60 }, { 20, 100 }, "add ranch", font));
                uimanager.addbutton(Button({ 200, 60 }, { 20, 175 }, "add mustard", font));
                uimanager.addbutton(Button({ 200, 60 }, { 20, 250 }, "Serve", font));
                pizza.clearpizzaingredients();
            }
        }
        else if (clickedIndex == 4)
        {
            state = gamestate::Milkshake_bar;
            blenderopen = false;
            pizza.clearSaladIngredients();
            pizza.clearSaladNames();
            pizza.clearpizzaingredients();
            pizza.clearmilk();
            pizza.clearMilkNames();
            uimanager.clearbutton();
            uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
            uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
            uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 160 }, "blend", font));
        }

        
        if (state == gamestate::Milkshake_bar && clickedIndex == 5)
        {
            pizza.addblenderimage(blenderbackground);
            blenderopen = true;
            uimanager.addbutton(Button({ 200, 60 }, { 30, 90 }, "Serve", font));
        }

        if (state == gamestate::Milkshake_bar && clickedIndex == 6)
        {

            // milk Ingredient Score
            int milkScore = 0;
            vector<string> requiredMilk = currentOrder->getFlavours();

            if (requiredMilk.empty()) {
                milkScore = 100;
            }
            else {
                vector<string> placedMilk = pizza.getPlacedMilkNames();
                int correctCount = 0;
                for (const string& req : requiredMilk) {
                    for (const string& pl : placedMilk) {
                        if (pl == req) { correctCount++; break; }
                    }
                }
                milkScore = (correctCount * 100) / (int)requiredMilk.size();

                // for extra unwanted ingredients
                for (const string& pl : placedMilk) {
                    bool inOrder = false;
                    for (const string& req : requiredMilk) {
                        if (pl == req) { inOrder = true; break; }
                    }
                    if (!inOrder) milkScore -= 5;
                }
                if (milkScore < 0) milkScore = 0;
                if (milkScore > 100) milkScore = 100;
            }

            if (milkScore >= 80)      milkResultLabel.setString("Perfect Milkshake!");
            else if (milkScore >= 50) milkResultLabel.setString("Pretty Good!");
            else                      milkResultLabel.setString("Needs Work!");

            milkScoreText.setString("Milkshake Score: " + to_string(milkScore) + "/100");



            if (difficultMode && difficultRound == 0) {
                Cscore = milkScore; // round 1
                difficultRound = 1;
                state = gamestate::ORDER_SCREEN;
                currentOrder->generateDifferentFrom(firstOrderType);
                uimanager.clearbutton();
                uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
                uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
                uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
                uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
                uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
            }
            else 
            {
                if (difficultMode)
                {
                    sf::Time elapsed = waqt.getElapsedTime();
                    float deltaTime = elapsed.asSeconds();
                    string remarksdt;
					if (deltaTime < 15 ) 
                    {
                       remarksdt= "aray flash!";
                    }
                    else if (deltaTime < 30) 
                    {
                        remarksdt = "meh speed!";
                    }
                    else 
                    {
                        remarksdt = "Turtle is more fast!";
                    }
                    int finalScore = (Cscore + milkScore) / 2;
                    string remarks = finalScore >= 80 ? "Excellent Chef!" :
                        finalScore >= 50 ? "Good Effort!" : "Keep Practicing!";
                    milkResultLabel.setString(remarks + "\n" + remarksdt);
                    milkScoreText.setString("\nRound 1 Score: " + to_string(Cscore) + "/100\n" +"Round 2 Score: " + to_string(milkScore) + "/100\n" +"Final Score:   " + to_string(finalScore) + "/100");
                }
                difficultMode = false;
                waqt.restart();
                state = gamestate::ResultMilk_Screen;
                uimanager.clearbutton();
                uimanager.addbutton(Button({ 200, 60 }, { 300, 20 }, "Retry", font));
            }
        }

        if (state == gamestate::SALADBAR_SCREEN && clickedIndex == 5) {
            pizza.addRanchSplash(ranchbackground);
            pizza.addSaladName("ranch");
        }
        if (state == gamestate::SALADBAR_SCREEN && clickedIndex == 6) {
            pizza.addmustardSplash(mustardbackground);
            pizza.addSaladName("mustard");
        }

        // Salad Serve
        if (state == gamestate::SALADBAR_SCREEN && clickedIndex == 7) {

            int saladScore = 0;
            vector<string> requiredSalad = currentOrder->getSalad();

            if (requiredSalad.empty()) {
                saladScore = 100;
            }
            else {
                vector<string> placedSalad = pizza.getPlacedSaladNames();
                int correctCount = 0;
                for (const string& req : requiredSalad) {
                    for (const string& pl : placedSalad) {
                        if (pl == req) { correctCount++; break; }
                    }
                }
                saladScore = (correctCount * 100) / (int)requiredSalad.size();

                for (const string& pl : placedSalad) {
                    bool inOrder = false;
                    for (const string& req : requiredSalad) {
                        if (pl == req) { inOrder = true; break; }
                    }
                    if (!inOrder) saladScore -= 5;
                }
                if (saladScore < 0) saladScore = 0;
                if (saladScore > 100) saladScore = 100;
            }

            if (saladScore >= 80)      saladResultLabel.setString("Perfect Salad!");
            else if (saladScore >= 50) saladResultLabel.setString("Pretty Good!");
            else                       saladResultLabel.setString("Needs Work!");

            saladScoreText.setString("Salad Score: " + to_string(saladScore) + "/100");

            if (difficultMode && difficultRound == 0) {
                Cscore = saladScore;
                difficultRound = 1;
                state = gamestate::ORDER_SCREEN;
                currentOrder->generateDifferentFrom(firstOrderType);
                uimanager.clearbutton();
                uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
                uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
                uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
                uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
                uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
            }
            else
            {
                if (difficultMode) 
                {
                    sf::Time elapsed = waqt.getElapsedTime();
                    float deltaTime = elapsed.asSeconds();
                    string remarksdt;
                    if (deltaTime < 15)
                    {
                        remarksdt = "aray flash!";
                    }
                    else if (deltaTime < 30)
                    {
                        remarksdt = "meh speed!";
                    }
                    else
                    {
                        remarksdt = "Turtle is more fast!";
                    }
                    int finalScore = (Cscore + saladScore) / 2;
                    string remarks = finalScore >= 80 ? "Excellent Chef!" :
                        finalScore >= 50 ? "Good Effort!" : "Keep Practicing!";
                    saladResultLabel.setString(remarks + "\n" + remarksdt);
                    saladScoreText.setString(
                        "\nRound 1 Score: " + to_string(Cscore) + "/100\n" +
                        "Round 2 Score: " + to_string(saladScore) + "/100\n" +
                        "Final Score:   " + to_string(finalScore) + "/100"
                    );
                }
                difficultMode = false; waqt.restart();
                state = gamestate::ResultSalad_SCREEN;
                uimanager.clearbutton();
                uimanager.addbutton(Button({ 200, 60 }, { 300, 20 }, "Retry", font));
            }

        }

        // Oven Start
        if (state == gamestate::OVEN_SCREEN && clickedIndex == 5) {
            ovenRunning = true;
            currentClockFrame = 0;
            clockSprite.setTexture(clockTextures[0]);
            ovenClock.restart();
            clockFrameTimer = 0.f;
        }

        // Oven Serve
        if (state == gamestate::OVEN_SCREEN && clickedIndex == 6) {
            ovenRunning = false;
            serveStoppedAt = currentClockFrame;

            // ingredient Score
            int ingredientScore = 0;
            vector<string> required = currentOrder->getToppings();

            if (required.empty()) {
                ingredientScore = 50;
            }
            else {
                vector<string> placed = pizza.getPlacedNames();
                int correctCount = 0;
                for (const string& req : required) {
                    bool found = false;
                    for (const string& pl : placed) {
                        if (pl == req) { found = true; break; }
                    }
                    if (found) correctCount++;
                }
                ingredientScore = (correctCount * 50) / (int)required.size();

                for (const string& pl : placed) {
                    bool inOrder = false;
                    for (const string& req : required) {
                        if (pl == req) { inOrder = true; break; }
                    }
                    if (!inOrder) ingredientScore -= 5;
                }
                if (ingredientScore < 0) ingredientScore = 0;
                if (ingredientScore > 50) ingredientScore = 50;
            }

            // cooking Score
            int cookingScore = 0;
            int diff = serveStoppedAt - cookingTimeSeconds;
            if (diff == 0)            cookingScore = 50;
            else if (abs(diff) == 1)  cookingScore = 40;
            else if (abs(diff) == 2)  cookingScore = 25;
            else if (diff < 0)        cookingScore = 10;
            else                      cookingScore = 0;

            totalScore = ingredientScore + cookingScore;

            if (totalScore >= 80)      resultLabel.setString("Perfect Pizza!");
            else if (totalScore >= 50) resultLabel.setString("Pretty Good!");
            else                       resultLabel.setString("Needs Work!");

            scoreText.setString(
                "Ingredient Score: " + to_string(ingredientScore) + "/50\n" +
                "Cooking Score:    " + to_string(cookingScore) + "/50\n" +
                "Total Score:      " + to_string(totalScore) + "/100"
            );

            if (difficultMode && difficultRound == 0) {
                Cscore = totalScore;
                difficultRound = 1;
                state = gamestate::ORDER_SCREEN;
                currentOrder->generateDifferentFrom(firstOrderType);
                uimanager.clearbutton();
                uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
                uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
                uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
                uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
                uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
            }
            else {
                if (difficultMode) 
                {
                    sf::Time elapsed = waqt.getElapsedTime();
                    float deltaTime = elapsed.asSeconds();
                    string remarksdt;
                    if (deltaTime < 15)
                    {
                        remarksdt = "aray flash!";
                    }
                    else if (deltaTime < 30)
                    {
                        remarksdt = "meh speed!";
                    }
                    else
                    {
                        remarksdt = "Turtle is more fast!";
                    }
                    int finalScore = (Cscore + totalScore) / 2;
                    string remarks = finalScore >= 80 ? "Excellent Chef!" :
                        finalScore >= 50 ? "Good Effort!" : "Keep Practicing!";
                    resultLabel.setString(remarks + "\n" + remarksdt);
                    scoreText.setString(
                        "\nRound 1 Score: " + to_string(Cscore) + "/100\n" +
                        "Round 2 Score: " + to_string(totalScore) + "/100\n" +
                        "Final Score:   " + to_string(finalScore) + "/100"
                    );
                }
                difficultMode = false;
                waqt.restart();
                state = gamestate::ResultPizza_SCREEN;
                uimanager.clearbutton();
                uimanager.addbutton(Button({ 200, 60 }, { 300, 20 }, "Retry", font));
            }
        }

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
        {
            Vector2f mousepos = window.mapPixelToCoords(Mouse::getPosition(window));
            if (state == gamestate::COOKING_SCREEN) {
                if (cheese.getSprite().getGlobalBounds().contains(mousepos))
                {
                    draggedIngredients = &cheese; dragging = true;
                }
                else if (sausage.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &sausage; dragging = true;
                }
                else if (mushrooms.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &mushrooms; dragging = true;
                }
                else if (pepperoni.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &pepperoni;  dragging = true;
                }
                else if (olives.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &olives; dragging = true;
                }
                else if (onions.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &onions; dragging = true;
                }
            }
            else if (state == gamestate::SALADBAR_SCREEN)
            {
                if (onions2.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &onions2; dragging = true;
                }
                else if (olives2.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &olives2; dragging = true;
                }
                else if (lettuce.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &lettuce; dragging = true;
                }
                else if (cucumber.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &cucumber; dragging = true;
                }
                else if (chicken.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &chicken; dragging = true;
                }
                else if (tomatoes.getSprite().getGlobalBounds().contains(mousepos)) {
                    draggedIngredients = &tomatoes; dragging = true;
                }
            }
           /* else if (state == gamestate::Milkshake_bar)
            {
                if (banana.getSprite().getGlobalBounds().contains(mousepos))
                {
                    draggedIngredients = &banana;
                    dragging = true;
                }
                else if (strawberry.getSprite().getGlobalBounds().contains(mousepos))
                {
                    draggedIngredients = &strawberry;
                    dragging = true;
                }
                else if (mangoes.getSprite().getGlobalBounds().contains(mousepos))
                {
                    draggedIngredients = &mangoes;
                    dragging = true;
                }
                else if (vanicecream.getSprite().getGlobalBounds().contains(mousepos))
                {
                    draggedIngredients = &vanicecream;
                    dragging = true;
                }
                else if (chocolateicecream.getSprite().getGlobalBounds().contains(mousepos))
                {
                    draggedIngredients = &chocolateicecream;
                    dragging = true;
                }
                else if (tutifrutiicecream.getSprite().getGlobalBounds().contains(mousepos))
                {
                    draggedIngredients = &tutifrutiicecream;
                    dragging = true;
                }
            }*/
            else if (state == gamestate::Milkshake_bar)
            {
                if (!blenderopen)
                {
                    if (banana.getSprite().getGlobalBounds().contains(mousepos))
                    {
                        draggedIngredients = &banana;
                        dragging = true;
                        //draggedIngredients->getSprite().setOrigin(draggedIngredients->getSprite().getLocalBounds().width / 2.f, draggedIngredients->getSprite().getLocalBounds().height / 2.f);
                    }
                    else if (strawberry.getSprite().getGlobalBounds().contains(mousepos))
                    {
                        draggedIngredients = &strawberry;
                        dragging = true;
                        /*draggedIngredients->getSprite().setOrigin(
                            draggedIngredients->getSprite().getLocalBounds().width / 2.f,
                            draggedIngredients->getSprite().getLocalBounds().height / 2.f*/

                    }
                    else if (mangoes.getSprite().getGlobalBounds().contains(mousepos))
                    {
                        draggedIngredients = &mangoes;
                        dragging = true;
                        draggedIngredients->getSprite().setOrigin(
                            draggedIngredients->getSprite().getLocalBounds().width / 2.f,
                            draggedIngredients->getSprite().getLocalBounds().height / 2.f
                        );
                    }
                    else if (vanicecream.getSprite().getGlobalBounds().contains(mousepos))
                    {
                        draggedIngredients = &vanicecream;
                        dragging = true;
                        draggedIngredients->getSprite().setOrigin(
                            draggedIngredients->getSprite().getLocalBounds().width / 2.f,
                            draggedIngredients->getSprite().getLocalBounds().height / 2.f
                        );
                    }
                    else if (chocolateicecream.getSprite().getGlobalBounds().contains(mousepos))
                    {
                        draggedIngredients = &chocolateicecream;
                        dragging = true;
                        draggedIngredients->getSprite().setOrigin(
                            draggedIngredients->getSprite().getLocalBounds().width / 2.f,
                            draggedIngredients->getSprite().getLocalBounds().height / 2.f
                        );
                    }
                    else if (tutifrutiicecream.getSprite().getGlobalBounds().contains(mousepos))
                    {
                        draggedIngredients = &tutifrutiicecream;
                        dragging = true;
                        draggedIngredients->getSprite().setOrigin(draggedIngredients->getSprite().getLocalBounds().width / 2.f, draggedIngredients->getSprite().getLocalBounds().height / 2.f);
                    }
                }
            }
        }

        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            if (dragging && draggedIngredients) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (state == gamestate::COOKING_SCREEN) {
                    pizza.placeIngredient(mousePos, draggedIngredients->getSprite());
                    pizza.addIngredientName(
                        draggedIngredients == &cheese ? "cheese" :
                        draggedIngredients == &sausage ? "sausage" :
                        draggedIngredients == &mushrooms ? "mushrooms" :
                        draggedIngredients == &pepperoni ? "pepperoni" :
                        draggedIngredients == &olives ? "olives" :
                        draggedIngredients == &onions ? "onions" : "unknown");
                }
                else if (state == gamestate::SALADBAR_SCREEN) {
                    pizza.placeSaladIngredient(mousePos, draggedIngredients->getSprite());
                    pizza.addSaladName(
                        draggedIngredients == &lettuce ? "lettuce" :
                        draggedIngredients == &onions2 ? "onions" :
                        draggedIngredients == &olives2 ? "olives" :
                        draggedIngredients == &cucumber ? "cucumbers" :
                        draggedIngredients == &chicken ? "chicken" :
                        draggedIngredients == &tomatoes ? "tomatoes" : "unknown");
                }
                else if (state == gamestate::Milkshake_bar)
                {
                    pizza.placemilkingredient(mousePos, draggedIngredients->getSprite());

                    pizza.addMilkName(
                        draggedIngredients == &banana ? "bananas" :
                        draggedIngredients == &strawberry ? "strawberries" :
                        draggedIngredients == &mangoes ? "mangoes" :
                        draggedIngredients == &vanicecream ? "vanilla icecream" :
                        draggedIngredients == &chocolateicecream ? "chocolate icecream" :
                        draggedIngredients == &tutifrutiicecream ? "tutifruti icecream" : "unknown");
                }

                // Respawn ingredient back to bowl
                draggedIngredients->respawn();
                draggedIngredients = nullptr;
                dragging = false;
            }
        }
    }
}

void Game::update() {
    uimanager.update(window);
    if (dragging && draggedIngredients) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        draggedIngredients->getSprite().setPosition(mousePos);
    }

    if (state == gamestate::OVEN_SCREEN && ovenRunning) {
        float elapsed = ovenClock.restart().asSeconds();
        clockFrameTimer += elapsed;
        if (clockFrameTimer >= 1.f) {
            clockFrameTimer = 0.f;
            if (currentClockFrame < 20) {
                currentClockFrame++;
                clockSprite.setTexture(clockTextures[currentClockFrame]);
                clockSprite.setScale(
                    200.f / clockTextures[currentClockFrame].getSize().x,
                    200.f / clockTextures[currentClockFrame].getSize().y
                );
            }
            else {
                ovenRunning = false;
            }
        }
    }
}

void Game::render() {
    window.clear();

    if (state == gamestate::HOMEPAGE) {
        window.draw(homeBackground);
        window.draw(ghazaal);
        window.draw(muaaz);
        window.draw(shahbaz);
    }
    else if (state == gamestate::ORDER_SCREEN) {
        window.draw(orderBackground);
        currentOrder->draw(window);
    }
    else if (state == gamestate::COOKING_SCREEN) {
        window.draw(cookingBackground);
        pizza.draw(window);
        cheese.draw(window);
        sausage.draw(window);
        mushrooms.draw(window);
        pepperoni.draw(window);
        olives.draw(window);
        onions.draw(window);
    }
    else if (state == gamestate::OVEN_SCREEN) {
        window.draw(ovenBackground);
        window.draw(cookingTimeText);
        window.draw(clockSprite);
    }
    else if (state == gamestate::ResultPizza_SCREEN) {
        window.draw(resultBackground);
        window.draw(resultLabel);
        window.draw(scoreText);
    }
    else if (state == gamestate::ResultSalad_SCREEN) {
        window.draw(resultBackground);
        window.draw(saladResultLabel);
        window.draw(saladScoreText);
    }
    else if (state == gamestate::ResultMilk_Screen) {
        window.draw(resultBackground);
        window.draw(milkResultLabel);
        window.draw(milkScoreText);
    }
    else if (state == gamestate::SALADBAR_SCREEN)
    {
        window.draw(saladbarbackground);
        pizza.drawsalad(window);
        olives2.draw(window);
        cucumber.draw(window);
        chicken.draw(window);
        lettuce.draw(window);
        onions2.draw(window);
        tomatoes.draw(window);
    }
    else if (state == gamestate::Milkshake_bar)
    {
        window.draw(milkshakebackground);
        pizza.drawmilk(window);
        //only draw ingredients and generate matrix when blender not yet blended
        if (!blenderopen)
        {
            banana.draw(window);
            strawberry.draw(window);
            mangoes.draw(window);
            vanicecream.draw(window);
            chocolateicecream.draw(window);
            tutifrutiicecream.draw(window);
            pizza.generatematrix1(800, 600);
        }
    }

    uimanager.draw(window);
    window.display();
}