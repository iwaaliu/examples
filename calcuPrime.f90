!this code is used to calculate all prime numbers within given N.
!for instance, N=10, we calculate all prime numbers<10: 2,3,5,7.
!we set all non-prime to 0, and print non-zero elements in array A(N), where A(i)=i is initialized.
integer,allocatable::A(:)

print*, "Please input your N:(N<2^32)"
read(*,*) N
allocate(A(N))
if(N<3)then
   print*, "N<=2,only 1 prime: 2"
   stop
endif
do i=1,N
   A(i)=i
enddo

A(1)=0
do j=2,N   
   in=j
   if(A(in).ne.0) then
      i=2
      k=2*in
      do while (k.le.N)
         A(k)=0
         i=i+1
         k=i*in
      enddo
   endif
enddo
j=0
do i=1,n
   if(A(i).ne.0) then
      print*, A(i)
      j=j+1
   endif
enddo
print*, "There are ", j, "prime numbers in total within N=",N

end program
