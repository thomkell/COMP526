! COMP526 HW7
! Thomas Keller, 11/16/2022
! Assign7, txt

PROGRAM length
        IMPLICIT NONE
        
        INTERFACE 
           SUBROUTINE outFile(h)
             REAL, INTENT(IN) :: h
             !REAL, INTENT(OUT) :: vec
           END SUBROUTINE outFile
        END INTERFACE
        
        ! Declare local variables
        REAL :: h = 0
        real :: integral = 0

        ! parameters
        real, parameter :: a = -0.5
        real, parameter :: b = 0.5 
        real, parameter :: n = 20
        
        ! stepsize
        h = ((b-a)/n)
        
        ! call function with h
        CALL outFile(h)

        ! output data
        integral = arcLength(h) 
        write(*,*) 'length = ', integral 

        CONTAINS
        real function arcLength(h)
                implicit NONE
                real, intent(IN) :: h
                Real, Dimension( 2,20 ) :: a2
                integer :: i
                integer :: iostat
                real :: x
                real :: deriv
                real :: sum = 0

                !readfile
                open (2, file = 'derivative.txt', FORM="FORMATTED", status = 'old')
                Read ( 2, * ) 
                do i = 1,100
                    ! iostate for end-of-file
                    read(2,*, IOSTAT=iostat) a2( :,i )
                    if( iostat < 0 )then
                        write(6,'(A)') 'EOF'
                        exit
                    else if( iostat > 0 )then
                        write(6,'(A)') 'error reading file'
                        stop
                    end if
                end do 

                do i = 1,20
                    x = a2( 1,i )
                    deriv = a2( 2,i )
                end do

                ! calc sum
                do i=1,19
                    sum = sum + abs(1/((a+i*h)*(a+i*h)+1))
                end do

                arcLength = h*((a2(2,1)/2)+sum+a2(2,20))

                close(2)

        end function arcLength
        END PROGRAM length
        
        !-----outFile---------------------------------------------------

        SUBROUTINE outFile(h)
        
        IMPLICIT NONE

        !REAL, INTENT(OUT) :: Area
        Real, INTENT(IN) :: h
        Real, dimension(0:20) :: vec
        Real, dimension(0:20) :: derivative
        integer :: i

        ! calculate vec and derivative
        do i = 0,20
            vec(i) = -0.5+(i*h) !h
            derivative(i) = 1/((vec(i)*vec(i))+1)
        end do

        ! output data into a file 
        open(1, file = 'derivative.txt', FORM="FORMATTED", status='UNKNOWN')
        
        write(1,'(a4,6X,a5)') 'x',"f'(x)"

        do i = 0,20
            write(1,'(f6.3, 3X, f6.4)') vec(i), derivative(i)
        end do  
        close(1) 
        
        END SUBROUTINE outFile