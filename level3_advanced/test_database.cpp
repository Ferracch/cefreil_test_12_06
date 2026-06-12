#include <gtest/gtest.h>
#include "mock_database.h"

// TODO STUDENTE 0: Crea la Test Fixture "DatabaseTest".
class DatabaseTest : public testing::Test {
protected:
    MockDatabase db;

    void SetUp() override {
        db.Connect();
        db.InsertUser("admin", 1, "administrator");
        db.InsertUser("guest", 2, "visitor");
    }

    void TearDown() override {
        db.Disconnect();
    }
};


// TODO STUDENTE 1: Usando TEST_F, scrivi un test che verifichi l'utente "admin".
TEST_F(DatabaseTest, RetrievesExistingAdmin) {
    UserRecord* user = db.GetUser("admin");
    ASSERT_NE(user, nullptr);
    EXPECT_EQ(user->id, 1);
    EXPECT_EQ(user->role, "administrator");
}

// TODO STUDENTE 2: Usando TEST_F, scrivi un test che verifichi l'utente "guest".
TEST_F(DatabaseTest, RetrievesExistingGuest) {
    UserRecord* user = db.GetUser("guest");
    ASSERT_NE(user, nullptr);
    EXPECT_EQ(user->id, 2);
    EXPECT_EQ(user->role, "visitor");
}

// TODO STUDENTE 3: Usando TEST_F, scrivi un test che prova a recuperare un utente 
// non esistente (es. "hacker") e verifica che il risultato sia nullptr.
TEST_F(DatabaseTest, UnknownUserReturnsNull) {
    User* user = db.GetUser("hacker");
    EXPECT_EQ(user, nullptr);
}

// TODO STUDENTE 4: Usando TEST_F, disconnetti esplicitamente il DB all'interno 
// del test (chiamando Disconnect()) e verifica che chiamare GetUser("admin") 
// restituisca nullptr (il DB non deve rispondere se non e' connesso).
TEST_F(DatabaseTest, GetUserFailsWhenDisconnected) {
    db.Disconnect();
    UserRecord* user = db.GetUser("admin");
    EXPECT_EQ(user, nullptr);
}