/*----------------------------------------------------------------------------*/
/* Linker Settings                                                            */
--retain="*(.intvecs)"

--stack_size=0x700
/*----------------------------------------------------------------------------*/
/* Section Configuration                                                      */
SECTIONS
{
    systemHeap      : {} >> L2SRAM_UMAP0 | L2SRAM_UMAP1
    .MCPILogBuffer  : {} > L2SRAM_UMAP0
}
/*----------------------------------------------------------------------------*/
