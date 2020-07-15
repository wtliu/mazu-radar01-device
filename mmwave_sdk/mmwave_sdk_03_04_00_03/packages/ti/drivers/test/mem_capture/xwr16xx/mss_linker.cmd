/*----------------------------------------------------------------------------*/
/* Linker Settings                                                            */
--retain="*(.intvecs)"

/*----------------------------------------------------------------------------*/
/* Section Configuration                                                      */
SECTIONS
{
    systemHeap : {}  > DATA_RAM
    .l3Data          > L3_RAM
    .cbuffL3Memory   > L3_RAM
    .demoSystemCfg   > HS_RAM
}
/*----------------------------------------------------------------------------*/

