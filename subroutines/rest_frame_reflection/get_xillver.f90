!-----------------------------------------------------------------------
    subroutine get_xillver(ear, ne, dim, dimCp, param_xillPL, param_xillCp, Cp, photar)
!!! This routine calls the correct version of xillver based on the Cp !!!
!!!   Arg:
      !  ear: energy grid
      !  ne: number of grid points
      !  param6: array of xillver parameters for xillver, xillverD
      !  param7: array of xillver parameters for xillverDCp
      !  ifl : parameter to call xspec model
      !  Cp : chooses xillver model
      !      -1 xillver      1e15 density and powerlaw illumination  
      !       1 xillverD     high density and powerlaw illumination
      !       2 xillverDCp   high density and nthcomp  illumination
      ! photar: (output) xillver energy spectrum

!!! Last change: Gullo - 2023 Nov
      use xillver_tables
      implicit none
      integer, intent(in)  :: ne, Cp, dim, dimCp
      real   , intent(in)  :: ear(0:ne), param_xillPL(dim), param_xillCp(dimCp)
      real   , intent(out) :: photar(ne)

      real                :: photer(ne)
      integer             :: ifl

      ifl = 0
      if( Cp .eq. -1 )then         !xillver
         ! write(*,*) 'xillver parameters', param6
         call xsatbl(ear, ne, param_xillPL, trim(pathname_xillver), ifl, photar, photer)
      else if( Cp .eq. 1 )then     !xillverD
         ! write(*,*) 'xillver powerlaw parameters', param_xillPL
         ! write(*,*) trim(pathname_xillverD)
         call xsatbl(ear, ne, param_xillPL, trim(pathname_xillverD), ifl, photar, photer)
      else if ( Cp .eq. 2 )then    !xillverDCp
         ! write(*,*) 'xillverCp parameters', param_xillCp
         call xsatbl(ear, ne, param_xillCp, trim(pathname_xillverDCp), ifl, photar, photer)
      else
         write(*,*) 'No xillver model available for this configuration'
         stop 
      end if
      return
    end subroutine get_xillver
!-----------------------------------------------------------------------
