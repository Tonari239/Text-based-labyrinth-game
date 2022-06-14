#include "doctest.h"
#include "grid.h"

TEST_SUITE("Grid tests")
{
    TEST_CASE("Constructor with rows and columns")
    {
        int rows = 10;
        int cols = 10;
        Grid g(rows, cols);
        CHECK(g.getRows() == rows);
        CHECK(g.getCols() == cols);

        CHECK(g.getCell(5, 5).getSymbol() == '?');
    }

    TEST_CASE("Copy Constructor")
    {
        Grid g1(5, 5);
        Grid g2(g1);

        CHECK(g1.getRows() == g2.getRows());
        CHECK(g1.getCols() == g2.getCols());
        CHECK(g1.getCell(1, 1).getSymbol() == g2.getCell(1, 1).getSymbol());
    }

    TEST_CASE("Operator =")
    {
        Grid g1(5, 5);
        Grid g2(1,3);
        g2 = g1;
        CHECK(g1.getRows() == g2.getRows());
        CHECK(g1.getCols() == g2.getCols());
        CHECK(g1.getCell(1, 1).getSymbol() == g2.getCell(1, 1).getSymbol());
    }

    TEST_CASE("Set cell value")
    {
        Grid g1(5, 5);
        g1.setCellValue(3, 3, 'H');
        CHECK(g1.getCell(3,3).getSymbol() == 'H');
    }

    TEST_CASE("Set cell value throws exception when out of bounds")
    {
        Grid g1(5, 5);
        
        CHECK_THROWS(g1.setCellValue(-13, 3, 'H'));
    }

    TEST_CASE("Get cell value")
    {
        Grid g1(5, 5);
        CHECK(g1.getCell(3, 3).getSymbol() == '?');
        CHECK_THROWS(g1.getCell(10, 10));
    }

    TEST_CASE("Mark cell as visited")
    {
        Grid g1(5, 5);
        CHECK(g1.getCell(3, 3).hasBeenVisited() == false);
        g1.markCellAsVisited(3, 3);
        CHECK(g1.getCell(3, 3).hasBeenVisited() == true);

    }

    TEST_CASE("Mark cell as visited throws exception when out of bounds")
    {
        Grid g1(5, 5);

        CHECK_THROWS(g1.markCellAsVisited(-13, 3));
    }
}