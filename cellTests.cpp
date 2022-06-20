#include "doctest.h"
#include "cell.h"

TEST_SUITE("Cell tests")
{
    TEST_CASE("Default constructor")
    {
        Cell c;

        CHECK(c.hasBeenVisited()==false);
        CHECK(c.isOccupied() == false);
        CHECK(c.getSymbol() == '?');
    }

    TEST_CASE("Set symbol")
    {
        Cell c;
        c.setSymbol('H');
        CHECK(c.getSymbol() == 'H');

        c.setSymbol('.');
        CHECK(c.getSymbol() == '.');
    }

    TEST_CASE("Set symbol throws exception")
    {
        Cell c;
        CHECK_THROWS(c.setSymbol('F'));
    }

    TEST_CASE("Get symbol")
    {
        Cell c;
        c.setSymbol('M');
        CHECK(c.getSymbol() == 'M');
    }

    TEST_CASE("Set visited status")
    {
        Cell c;
        CHECK(c.hasBeenVisited() == false);

        c.setVisitedStatus(true);
        CHECK(c.hasBeenVisited() == true);

        c.setVisitedStatus(false);
        CHECK(c.hasBeenVisited() == false);
    }

    TEST_CASE("Mark visited")
    {
        Cell c;
        c.markVisited();
        CHECK(c.getSymbol() == '.');
    }

    TEST_CASE("Has been visited")
    {
        Cell c;
        CHECK(c.hasBeenVisited() == false);
        c.markVisited();
        CHECK(c.hasBeenVisited() == true);
    }
}