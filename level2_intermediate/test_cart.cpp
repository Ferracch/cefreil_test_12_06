#include <gtest/gtest.h>
#include "shopping_cart.h"

// ESEMPIO PROFESSORE:
TEST(ShoppingCartTest, StartsEmptyAndAddsSuccessfully) {
    ShoppingCart cart;
    EXPECT_EQ(cart.GetItemCount(), 0);
    EXPECT_EQ(cart.GetTotalCents(), 0);
    
    cart.AddItem("Mela", 150); // 1.50 euro
    EXPECT_EQ(cart.GetItemCount(), 1);
    EXPECT_EQ(cart.GetTotalCents(), 150);
}

// TODO STUDENTE 1: Aggiungi tre prodotti diversi al carrello.
// Usa EXPECT_EQ per verificare il conteggio totale e il prezzo totale.
// Usa messaggi personalizzati << se l'asserzione fallisce.
TEST(ShoppingCartTest, CalculatesTotalForMultipleItems) {
    // IL TUO CODICE QUI
    ShoppingCart cart;
    cart.AddItem("Banana", 100); // 1.00 euro  
    cart.AddItem("Arancia", 200); // 2.00 eur
    cart.AddItem("Pera", 250); // 2.50 euro
    EXPECT_EQ(cart.GetItemCount(), 3) << "Il conteggio degli articoli dovrebbe essere 3 dopo aver aggiunto tre prodotti.";
    EXPECT_EQ(cart.GetTotalCents(), 550) << "Il totale in centesimi dovrebbe essere 550";

}

// TODO STUDENTE 2: Testa l'estrazione di un prodotto esistente.
// Ricorda di controllare che il puntatore restituito da ExtractItem NON sia nullptr 
// usando ASSERT_NE prima di verificarne il nome e il prezzo.
// Dopo averlo estratto, verifica che il totale e il conteggio del carrello siano diminuiti.
// Ricordati di fare delete del puntatore estratto!
TEST(ShoppingCartTest, ExtractsExistingItemCorrectly) {
    // IL TUO CODICE QUI
    ShoppingCart cart;
    cart.AddItem("Latte", 300); // 3.00 euro
    Item* extracted = cart.ExtractItem("Latte");
    ASSERT_NE(extracted, nullptr) << "ExtractItem dovrebbe restituire un puntatore";
    EXPECT_EQ(extracted->name, "Latte") << "Il nome dell'articolo è sbagliato";
    EXPECT_EQ(extracted->price_cents, 300) << "Il prezzo dell'articolo è sbagliato";
    EXPECT_EQ(cart.GetItemCount(), 0) << "Il conteggio degli articoli dovrebbe essere 0 dopo l'estrazione";
    EXPECT_EQ(cart.GetTotalCents(), 0) << "Il conto dovrebbe essere 0";
    delete extracted; // Pulizia della memoria  
}

// TODO STUDENTE 3: Testa l'estrazione di un prodotto NON esistente.
// Verifica che ExtractItem restituisca nullptr.
TEST(ShoppingCartTest, ExtractNonExistingItemReturnsNull) {
    // IL TUO CODICE QUI
    ShoppingCart cart;
    cart.AddItem("Pane", 200); // 2.00 euro
    Item* extracted = cart.ExtractItem("Mela");
    EXPECT_EQ(extracted, nullptr) << "ExtractItem dovrebbe restituire nullptr per un prodotto non esistente";   
    delete extracted; // Pulizia della memoria (anche se è nullptr, è sicuro fare delete)
}