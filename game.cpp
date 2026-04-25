#include "game.h"
#include "UImanager.h"
Game::Game(RenderWindow& win)
    : window(win),
    pizza(),
    olives("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\olive-.png", { 30, 550 }),
    cheese("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\cheese--.png", { 540, 540 }),
    sausage("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\sausage-.png", { 670, 550 }),
    mushrooms("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\mushroom-.png", { 160, 545 }),
    pepperoni("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\pep--.png", { 420, 550 }),
    onions("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\onion--.png", { 270, 538 }),
    onions2("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\onion--.png", { 265, 538 }),
    cucumber("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\cucumber--.png", { 545, 538 }),
    tomatoes("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\tomato.png", { 145, 545 }),
    chicken("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\chicken.png", { 670, 545 }),
    lettuce("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\lettuce-.png", { 30, 550 }),
    olives2("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\olive---.png", { 420, 550 }),//c2
    banana("C:\\Users\\HM Traders\\Desktop\\ooop project\\banana.png", { 5, 550 }),
    strawberry("C:\\Users\\HM Traders\\Desktop\\ooop project\\strawberry.png", { 135, 545 }),
    mangoes("C:\\Users\\HM Traders\\Desktop\\ooop project\\mangoes.png", { 265, 540 }),
    vanicecream("C:\\Users\\HM Traders\\Desktop\\ooop project\\vanicecream.png", { 395, 550 }),
    chocolateicecream("C:\\Users\\HM Traders\\Desktop\\ooop project\\chocolateicecream.png", { 515, 550 }),
    tutifrutiicecream("C:\\Users\\HM Traders\\Desktop\\ooop project\\tutifrutiicecream.png", { 650, 550 })
{
    state = gamestate::HOMEPAGE;

    // Load font
    if (!font.loadFromFile("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\hot-pizza\\hot-pizza.normal.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }
    //add buttons
    uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
    uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
    uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
    uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
    uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));


    // Load textures
    orderBgTex.loadFromFile("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\order.png");
    cookingBgTex.loadFromFile("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\cooking station.png");
    ovenBgTex.loadFromFile("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\oven.jpeg");
    homeBgTex.loadFromFile("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\outside.png");
    saladbarTex.loadFromFile("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\salad bar.png");
    ketchupTex.loadFromFile(("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\ranch.png"));
    mustardTex.loadFromFile(("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\mustard.png"));
    milkshakeTex.loadFromFile(("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\milkshake.jpeg"));
    blenderTex.loadFromFile(("C:\\Users\\HM Traders\\Desktop\\project assets\\project assets\\blend.jpeg"));
    // Assign textures
    orderBackground.setTexture(orderBgTex);
    saladbarbackground.setTexture(saladbarTex);
    cookingBackground.setTexture(cookingBgTex);
    ovenBackground.setTexture(ovenBgTex);
    homeBackground.setTexture(homeBgTex);
    ketchupbackground.setTexture(ketchupTex);
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
    pizza.generateMatrix(800, 600); // center in 800x800 window

    // Start background music
    audio.start("C:\\Users\\HM Traders\\Desktop\\ooop project\\Mambo Italiano.ogg");

    //intro box

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

        int clickedIndex;
        uimanager.handleEvents(window, event, clickedIndex);
        if (clickedIndex == 0) {
            state = gamestate::ORDER_SCREEN;
            uimanager.clearbutton();
            uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
            uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
            uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 90}, "milkshake", font));
            currentOrder->generateRandom(); // Generate a new random order when the button is clicked
        }
        else if (clickedIndex == 1)
        {
            state = gamestate::COOKING_SCREEN;
            pizza.clearSaladIngredients();
            pizza.clearpizzaingredients();
            pizza.clearmilk();
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
            pizza.clearpizzaingredients();
            pizza.clearmilk();
            uimanager.clearbutton();
            uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
            uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
            uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));

        }
        else if (clickedIndex == 3)
        {
            state = gamestate::SALADBAR_SCREEN;
            pizza.clearSaladIngredients();
            pizza.clearpizzaingredients();
            pizza.clearmilk();
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
                pizza.clearpizzaingredients();
            }
        }
        else if (clickedIndex == 4)
        {
            state = gamestate::Milkshake_bar;
            pizza.clearSaladIngredients();
            pizza.clearpizzaingredients();
            pizza.clearmilk();
            uimanager.clearbutton();
            pizza.generatematrix1(800, 600);
            uimanager.addbutton(Button({ 200, 60 }, { 20, 20 }, "Order", font));
            uimanager.addbutton(Button({ 200, 60 }, { 220, 20 }, "Kitchen", font));
            uimanager.addbutton(Button({ 200, 60 }, { 400, 20 }, "Oven", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 20 }, "Salad bar", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 90 }, "milkshake", font));
            uimanager.addbutton(Button({ 200, 60 }, { 600, 160}, "blend", font));
        }
        else if (state == gamestate::Milkshake_bar && clickedIndex == 7)
        {
                pizza.addblenderimage(blenderbackground);
        }
        if (state == gamestate::SALADBAR_SCREEN && clickedIndex == 5) {
            pizza.addKetchupSplash(ketchupbackground);

        }
        if (state == gamestate::SALADBAR_SCREEN && clickedIndex == 6) {
            pizza.addmustardSplash(mustardbackground);
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
            else if (state == gamestate::Milkshake_bar)
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
            }

        }
        if (event.type == sf::Event::MouseButtonReleased &&event.mouseButton.button == sf::Mouse::Left) {
            if (dragging && draggedIngredients) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (state == gamestate::COOKING_SCREEN) {
                    pizza.placeIngredient(mousePos, draggedIngredients->getSprite());
                }
                else if (state == gamestate::SALADBAR_SCREEN) {
                    pizza.placeSaladIngredient(mousePos, draggedIngredients->getSprite());
                }
				else if (state == gamestate::Milkshake_bar)
                {
                    pizza.placemilkingredient(mousePos, draggedIngredients->getSprite());
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
    uimanager.update(window);   // hover updates every frame
    if (dragging && draggedIngredients) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        draggedIngredients->getSprite().setPosition(mousePos);
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

        // Draw ingredient bowls
        cheese.draw(window);
        sausage.draw(window);
        mushrooms.draw(window);
        pepperoni.draw(window);
        olives.draw(window);
        onions.draw(window);
    }
    else if (state == gamestate::OVEN_SCREEN) {
        window.draw(ovenBackground);
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
        banana.draw(window);
		strawberry.draw(window);
		mangoes.draw(window);
		vanicecream.draw(window);
		chocolateicecream.draw(window);
		tutifrutiicecream.draw(window);
	}
    uimanager.draw(window);
    window.display();
}
