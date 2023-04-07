! COMP526 HW6
! Thomas Keller, 11/12/2022
! Arnoldi Iteration
program arnoldiIter
    IMPLICIT NONE

    !define inputs
    integer, dimension (7,7) :: A = reshape((/&
     2, -1, 0, 0, 0, 0, 0, &
    -1, 2, -1, 0, 0, 0, 0, &
     0, -1, 2, -1, 0, 0, 0, &
     0, 0, -1, 2, -1, 0, 0, &
     0, 0, 0, -1, 2, -1, 0, &
     0, 0, 0, 0, -1, 2, -1, &
     0, 0, 0, 0, 0, -1, 2  /), (/ 7,7/))

    real, parameter :: pi = 3.1415927
    real, parameter :: s = pi/4
    real, dimension(7) :: b = &
    s*s*(/ 2*sin(s)+s*cos(s),&
    2*sin(2*s)+2*s*cos(2*s),&
    2*sin(3*s)+3*s*cos(3*s),&
    2*sin(4*s)+4*s*cos(4*s),&
    2*sin(5*s)+5*s*cos(5*s),&
    2*sin(6*s)+6*s*cos(6*s),&
    2*sin(7*s)+7*s*cos(7*s)+2*pi /)

    ! q1 vector
    real, dimension(7) :: y = 0

    INTEGER :: i = 0, m = 7, j = 0, k = 0, g = 0, f = 0
    real :: l = 0

    ! Output matrices
    real, dimension (7, 8) :: Q = 0
    real, dimension (8, 7) :: H = 0
    real, dimension (7, 8) :: T = 0
    real, dimension (7, 7) :: T2 = 0

    ! print inputs
    WRITE(*,*) 'Inputs:'
    ! A
    do i=1,7
        write(*,*) (A(i,j),j=1,7)
    enddo
    WRITE(*,*) '-----------------------'
    ! b
    WRITE(*,*) 'b: ',b
    WRITE(*,*) '-----------------------'
    ! Q
    Q(:,1) = b(:)
    do i=1,7
        write(*,*) (Q(i,j),j=1,7)
    enddo

    ! start calculation
    do i = 1,m

        ! A*Q
        do k = 1,m
            y(k) = DOT_PRODUCT(A(:,k),Q(:,i))
        end do

        ! calc H
        do k = 1,i
            l=0
            do g = 1,m
                l = l + Q(g,k)*y(g)
            end do
            H(k,i) = l

            do f = 1,m
                y(f) = y(f)-(Q(f,k)*H(k,i))
            end do

        end do

        ! norm
        H(i+1,i) = norm2(y)
        l = 0

        ! calc Q
        do f = 1,m
            Q(f,i+1) = l + y(f)/H(i+1,i)
        end do
    end do

    ! End result print
    WRITE(*,*) '---------Result--------'
    write(*,*) 'Q'
    do i=1,7
        write(*,*)(Q(i,j),j=1,8)
    enddo

    write(*,*)
    write(*,*) 'H'

    do i=1,8
        write(*,*) (H(i,j),j=1,7)
    enddo
    WRITE(*,*) '-----------------------'

    ! Check result: A*Q=Q*H
    T=MATMUL(A,Q)
    T2=MATMUL(Q,H)
    write(*,*) 'A*Q'
    do i=1,7
        write(*,*) (T(i,j),j=1,8)
    enddo
    WRITE(*,*) '-----------------------'
    write(*,*) 'Q*H'
    do i=1,7
        write(*,*) (T2(i,j),j=1,7)
    enddo
    end program