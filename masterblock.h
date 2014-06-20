#ifndef MASTERBLOCK_H
#define MASTERBLOCK_H

class MasterBlock
{
public:
    MasterBlock();
    int numberOfBlocks;
    const int BLOCK_SIZE = 7168;
    int indexOfFirstDefTableBlock;
};

#endif // MASTERBLOCK_H
