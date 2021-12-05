#include "../lib/library.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

extern "C" long long asm_foo(void);

TEST_CASE("Testing assembly functions"){
    SUBCASE("compute answer"){
        compute_answer();
        CHECK(compute_answer() == 42);
    }
    SUBCASE("increment pointer"){
        int64_t not_zero = 0;
        increment_pointer_int64(&not_zero);
        CHECK(not_zero != 0);
    }
    SUBCASE("asm_foo"){
        CHECK(asm_foo() == 1337);
    }
    SUBCASE("sum of four ints"){
        CHECK(sum_4_ints(1, 1, 1, 1) == 4);
    }
    SUBCASE("sum of two ints"){
        CHECK(sum_two_ints(1, 1) == 2);
    }
    SUBCASE("mul of two ints"){
        CHECK(mul_two_ints(4, 2) == 8);
    }
}
TEST_CASE("Day 1"){
    uint64_t input[] = {
            151,150,148,147,154,155,156,161,164,165,172,174,171,172,168,170,167,168,170,177,
            179,146,144,168,170,174,185,184,183,185,178,179,161,164,162,167,176,175,178,179,
            185,183,179,174,173,174,203,199,203,201,200,210,209,207,203,204,205,208,207,215,
            236,238,236,238,241,242,226,225,221,218,207,209,194,191,203,202,182,160,159,191,
            185,171,191,185,172,178,198,200,176,181,184,185,193,205,206,207,203,229,232,242,
            254,250,266,265,288,278,273,274,253,255,253,246,245,247,243,246,248,251,245,243,
            242,259,254,259,261,274,271,273,275,283,287,286,287,286,299,295,298,300,299,302,
            301,300,307,302,326,323,321,318,312,302,304,301,306,309,328,326,333,346,364,369,
            370,358,364,363,364,361,374,373,383,385,379,378,377,353,352,353,357,355,348,356,
            358,359,358,357,349,354,360,341,343,342,343,347,317,322,324,328,338,350,323,365,
            364,384,391,395,394,385,384,367,371,376,380,390,388,387,390,401,379,378,360,363,
            360,370,362,349,342,324,327,338,336,339,341,337,334,319,320,317,319,314,316,350,
            351,352,351,349,350,352,343,347,339,337,335,338,341,342,343,345,359,361,378,382,
            376,381,388,389,375,368,372,365,367,369,370,369,364,363,362,364,355,372,350,356,
            358,363,353,354,335,327,325,326,327,342,329,327,342,337,336,334,354,343,345,341,
            350,344,345,352,356,388,391,406,397,405,408,402,397,398,395,410,409,411,409,413,
            417,416,418,424,423,424,444,438,436,459,465,463,462,470,465,473,472,464,466,468,
            463,469,466,469,470,457,458,457,463,478,494,507,499,498,499,510,514,517,516,537,
            549,559,549,541,540,541,554,557,559,547,560,563,585,609,604,605,606,612,611,601,
            600,588,590,584,582,583,584,580,572,552,547,538,540,526,508,491,495,512,514,504,
            508,509,500,495,494,493,530,528,529,522,538,519,515,502,476,467,469,470,478,477,
            473,475,486,512,513,517,499,503,504,505,502,503,504,505,507,516,533,539,551,552,
            555,551,550,548,543,534,536,524,516,534,535,533,537,545,546,545,543,544,542,574,
            576,575,552,551,557,558,562,555,557,574,575,564,551,543,531,534,522,525,524,522,
            521,524,525,538,553,561,544,542,553,556,558,557,556,558,564,551,552,545,547,571,
            570,571,570,569,567,569,577,581,580,577,576,574,578,568,564,567,550,527,525,524,
            522,520,521,522,547,550,555,554,558,559,550,552,556,557,556,567,549,548,545,565,
            566,570,558,545,546,545,556,552,532,535,536,535,538,543,546,553,554,577,576,577,
            576,568,585,583,587,575,577,588,585,583,587,577,559,561,563,559,538,545,538,539,
            553,559,546,549,551,552,551,542,541,543,517,514,538,550,553,530,531,539,538,551,
            552,550,577,596,602,599,598,615,638,641,657,642,644,645,648,644,628,626,627,595,
            594,595,597,601,626,635,640,641,643,649,658,654,687,662,682,678,679,709,710,716,
            706,705,704,701,696,701,700,703,705,707,719,698,700,703,705,708,701,735,732,712,
            713,715,718,719,730,731,730,736,765,768,767,764,763,791,820,852,853,860,863,865,
            866,850,845,823,835,820,822,816,817,816,829,830,828,809,798,771,764,778,779,769,
            779,789,796,801,798,800,802,804,790,788,791,778,770,763,756,739,729,719,734,737,
            739,740,743,745,771,772,776,793,789,791,788,789,788,792,798,801,807,801,797,793,
            799,804,791,790,783,784,788,786,783,784,796,791,771,764,765,768,767,770,771,781,
            757,750,746,755,776,777,793,797,798,795,797,800,809,807,813,843,853,869,871,873,
            868,861,851,852,851,843,849,835,842,843,830,828,825,826,841,871,874,872,863,862,
            859,861,888,895,900,901,881,878,892,888,889,893,909,893,897,910,914,912,899,912,
            911,908,906,907,919,926,930,932,933,934,935,937,938,934,957,937,938,945,946,937,
            932,960,951,973,972,978,975,976,971,973,971,974,975,976,981,980,971,972,970,972,
            975,977,976,978,983,1002,1003,996,990,978,1012,1021,1027,1005,1021,1032,1031,1026,
            1036,1044,1018,1021,1042,1050,1052,1050,1052,1053,1055,1041,1032,1029,1027,1028,
            1041,1054,1047,1046,1050,1064,1029,1040,1039,1036,1037,1026,1033,1034,1025,1029,
            1025,1026,1024,1025,1021,1022,1019,1016,1020,1008,1003,1006,1040,1037,1044,1042,
            1044,1040,1048,1044,1054,1037,1034,1040,1041,1019,1015,1021,1042,1043,1037,1035,
            1032,1034,1043,1060,1050,1047,1052,1057,1060,1059,1047,1051,1053,1040,1046,1043,
            1041,1042,1046,1030,1029,1010,1022,1023,1025,1023,1032,1050,1051,1047,1044,1050,
            1057,1058,1061,1076,1077,1071,1081,1084,1118,1128,1123,1126,1119,1121,1118,1120,
            1119,1110,1118,1108,1118,1115,1130,1131,1120,1139,1134,1136,1113,1114,1118,1119,
            1114,1106,1077,1086,1088,1082,1095,1099,1100,1110,1114,1101,1116,1103,1102,1103,
            1111,1112,1109,1150,1172,1169,1170,1183,1188,1186,1205,1200,1205,1212,1207,1211,
            1227,1228,1222,1225,1226,1221,1224,1225,1224,1228,1220,1221,1222,1243,1247,1248,
            1259,1258,1246,1254,1251,1260,1261,1251,1252,1275,1273,1269,1291,1285,1274,1275,
            1278,1277,1287,1299,1300,1275,1281,1268,1298,1297,1299,1274,1270,1271,1278,1256,
            1248,1240,1224,1225,1230,1233,1230,1210,1209,1207,1213,1226,1224,1226,1230,1226,
            1227,1223,1234,1229,1228,1227,1226,1232,1230,1235,1208,1212,1213,1216,1215,1216,
            1239,1241,1245,1247,1253,1260,1252,1262,1272,1266,1267,1268,1266,1270,1277,1280,
            1282,1280,1271,1273,1272,1284,1282,1285,1286,1287,1286,1287,1288,1292,1304,1299,
            1288,1307,1315,1311,1301,1311,1345,1364,1359,1358,1373,1374,1369,1377,1378,1381,
            1383,1378,1385,1386,1389,1386,1365,1358,1352,1353,1360,1362,1361,1352,1353,1361,
            1360,1366,1359,1349,1359,1348,1374,1376,1374,1359,1369,1368,1374,1356,1358,1359,
            1351,1338,1339,1340,1323,1343,1352,1345,1340,1337,1338,1364,1362,1358,1355,1352,
            1356,1374,1376,1372,1370,1386,1384,1378,1381,1382,1385,1387,1386,1376,1378,1376,
            1372,1368,1363,1362,1364,1365,1369,1368,1364,1349,1374,1375,1376,1388,1364,1363,
            1371,1370,1372,1375,1364,1366,1355,1356,1370,1371,1353,1356,1358,1356,1351,1364,
            1373,1368,1369,1371,1372,1376,1362,1349,1344,1336,1335,1334,1333,1337,1336,1338,
            1344,1345,1344,1331,1332,1331,1328,1330,1329,1334,1333,1332,1328,1330,1329,1340,
            1341,1338,1339,1344,1356,1359,1360,1380,1389,1362,1359,1350,1368,1372,1377,1386,
            1383,1388,1389,1401,1399,1404,1394,1390,1391,1390,1392,1408,1398,1388,1352,1349,
            1327,1333,1327,1303,1295,1297,1296,1298,1306,1305,1312,1323,1327,1325,1327,1328,
            1317,1321,1320,1319,1301,1308,1327,1328,1326,1318,1323,1326,1330,1344,1347,1352,
            1355,1354,1364,1365,1350,1326,1345,1350,1351,1367,1362,1370,1372,1399,1415,1406,
            1405,1407,1414,1405,1406,1410,1400,1395,1396,1389,1382,1387,1394,1392,1391,1377,
            1374,1373,1361,1376,1381,1380,1365,1374,1356,1354,1353,1339,1347,1348,1347,1348,
            1330,1332,1317,1322,1321,1327,1326,1335,1340,1341,1331,1328,1315,1313,1321,1333,
            1339,1334,1340,1339,1333,1332,1335,1345,1346,1348,1344,1347,1356,1355,1356,1357,
            1358,1353,1354,1355,1354,1364,1366,1364,1359,1362,1367,1349,1353,1350,1327,1340,
            1370,1369,1364,1360,1357,1356,1349,1343,1345,1348,1352,1351,1369,1349,1358,1361,
            1359,1367,1368,1370,1382,1383,1386,1388,1375,1373,1372,1373,1390,1392,1391,1387,
            1371,1357,1351,1361,1362,1365,1367,1382,1383,1382,1379,1375,1373,1378,1376,1374,
            1376,1368,1375,1376,1386,1387,1388,1396,1414,1423,1433,1434,1421,1419,1417,1433,
            1435,1415,1432,1453,1454,1452,1451,1459,1462,1466,1494,1483,1480,1476,1472,1468,
            1469,1466,1443,1448,1457,1458,1452,1449,1442,1444,1446,1445,1441,1443,1448,1449,
            1450,1458,1454,1457,1458,1460,1458,1463,1469,1468,1459,1437,1450,1447,1472,1471,
            1480,1481,1473,1480,1476,1477,1464,1472,1481,1485,1489,1487,1488,1491,1470,1477,
            1486,1492,1493,1494,1495,1485,1493,1497,1492,1499,1501,1502,1514,1515,1517,1518,
            1516,1514,1517,1519,1517,1518,1516,1496,1519,1522,1524,1528,1529,1531,1524,1526,
            1528,1546,1538,1561,1570,1569,1574,1572,1571,1572,1564,1571,1576,1575,1576,1575,
            1580,1579,1564,1561,1566,1555,1546,1565,1567,1562,1563,1537,1538,1524,1532,1533,
            1567,1573,1574,1569,1571,1570,1571,1576,1571,1556,1554,1547,1551,1538,1540,1518,
            1521,1522,1532,1551,1555,1557,1580,1582,1583,1582,1579,1580,1581,1595,1596,1599,
            1595,1609,1622,1635,1636,1662,1666,1667,1670,1666,1669,1673,1672,1671,1661,1662,
            1683,1685,1682,1684,1692,1693,1692,1696,1669,1681,1682,1686,1702,1704,1706,1707,
            1711,1714,1720,1711,1708,1710,1709,1713,1720,1721,1722,1723,1706,1709,1710,1726,
            1739,1738,1740,1747,1732,1715,1712,1706,1708,1695,1691,1693,1691,1696,1692,1699,
            1696,1699,1683,1672,1674,1692,1731,1730,1705,1697,1713,1715,1722,1721,1707,1708,
            1717,1713,1714,1712,1703,1701,1707,1703,1705,1699,1734,1729,1741,1739,1754,1743,
            1746,1744,1745,1751,1779,1774,1775,1773,1776,1783,1782,1780,1778,1776,1771,1780,
            1748,1743,1740,1739,1740,1731,1732,1733,1730,1742,1744,1743,1751,1750,1751,1738,
            1746,1750,1753,1742,1744,1743,1735,1734,1731,1740,1725,1727,1709,1716,1717,1718,
            1712,1713,1708,1707,1723,1725,1726,1744,1745,1752,1753,1740,1739,1736,1733,1741,
            1751,1758,1769,1760,1777,1786,1787,1791,1792,1819,1825,1829,1828,1810,1812,1811,
            1813,1818,1820,1819,1832,1847,1846,1845,1846,1856,1851,1853,1851,1860,1849,1854,
            1879,1864,1851,1852,1851,1872,1879,1883,1876,1883,1884,1888,1887,1877,1900,1903,
            1912,1913,1899,1915,1919,1916,1917,1918,1932,1929,1932,1951,1962,1977,1972,1951,
            1943,1942,1947,1951,1974,1977,1979,1975,1932,1917,1919,1927,1932,1929,1927,1929,
            1928,1922,1923,1929,1938,1923,1910,1921,1922,1920,1903,1905,1895,1894,1923,1924,
            1921,1924,1926,1924,1951,1968,1974,1976,1995,2006,1991,1990,1989,1981,1971,1959,
            1951,1955,1953,1964,1963,1939,1946,1943,1941,1938,1927,1926,1925,1957,1937,1939,
            1942,1939,1952,1961,1976,1977,1989,1991,1965,1966,1955,1934,1935,1929,1944,1945,
            1935,1942,1970,1969,1942,1941,1966,1965,1934,1935,1953,1942,1943,1947,1964,1961,1963,1969};
    SUBCASE("Counting increments"){
        int res = count_increments(input, 2000);
        CHECK(res == 1139);
    }
    SUBCASE("3-element window"){
        uint64_t localInput[] = {1, 2, 3, 4, 5, 6};
        uint64_t destSize;
        auto res = three_element_window(localInput, 6, &destSize);
        CHECK(res[0] == 6);
        CHECK(res[1] == 9);
        CHECK(res[2] == 12);
        CHECK(res[3] == 15);
        CHECK(destSize == 4);
    }
}