main:
        push    rbp
        mov     rbp, rsp
        push    rbx
        sub     rsp, 56
        lea     rax, [rbp-48]
        mov     rdi, rax
        call    std::vector<int, std::allocator<int> >::vector() [complete object constructor]
        lea     rax, [rbp-48]
        mov     rdi, rax
        call    std::vector<int, std::allocator<int> >::begin()
        mov     QWORD PTR [rbp-56], rax
        lea     rax, [rbp-56]
        mov     esi, 0
        mov     rdi, rax
        call    __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >::operator++(int)
        mov     QWORD PTR [rbp-24], rax
        lea     rax, [rbp-24]
        mov     rdi, rax
        call    __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >::operator*() const
        mov     eax, DWORD PTR [rax]
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(int)
        lea     rax, [rbp-48]
        mov     rdi, rax
        call    std::vector<int, std::allocator<int> >::~vector() [complete object destructor]
        mov     eax, 0
        jmp     .L8
        mov     rbx, rax
        lea     rax, [rbp-48]
        mov     rdi, rax
        call    std::vector<int, std::allocator<int> >::~vector() [complete object destructor]
        mov     rax, rbx
        mov     rdi, rax
        call    _Unwind_Resume
.L8:
        mov     rbx, QWORD PTR [rbp-8]
        leave
        ret