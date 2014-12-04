  integer*8 A,bin
  character,allocatable::c(:)
  print *, 'go'
  bin=10
  write(A,*) bin
  print*, A
  print*, "Input a number "
  read(*,*) A
  n=log(A*1.)/log(2.)+1
  allocate(c(N))
  print*,"N=", N , "digits in total."
  ja=0
  j=1
  do while(a>0)
     if(mod(A,2)==1) ja=ja+1
     
     if(mod(A,2)==1) then
	c(N-j+1)='1'
else
   c(N-j+1)='0'
endif
a=a/2
j=j+1
enddo

print*, "we have ",ja, " 1's in this binary expression."
print*, c(:)
end program
