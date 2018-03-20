/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
 *  This file is part of cstl library
 *  Copyright (C) 2011 Avinash Dongre ( dongre.avinash@gmail.com )
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 * 
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/

#ifndef _C_DEQUE_H_
#define _C_DEQUE_H_

struct cstl_deque {
    struct cstl_object**pElements;
    int no_max_elements;
    int head;
    int tail;
    int no_of_elements;
    cstl_compare compare_fn;
    cstl_destroy destruct_fn;
};

extern struct cstl_deque* new_c_deque( int deq_size , cstl_compare fn_c, cstl_destroy fn_d);
extern cstl_error     push_back_c_deque (struct cstl_deque* pDeq, void* elem, size_t elem_size);
extern cstl_error     push_front_c_deque(struct cstl_deque* pDeq, void* elem, size_t elem_size);

extern cstl_error     front_c_deque     (struct cstl_deque* pDeq, void*);
extern cstl_error     back_c_deque      (struct cstl_deque* pDeq, void*);
extern cstl_error     pop_back_c_deque  (struct cstl_deque* pDeq);
extern cstl_error     pop_front_c_deque (struct cstl_deque* pDeq);
extern cstl_bool      empty_c_deque     (struct cstl_deque* pDeq);
extern int            size_c_deque ( struct cstl_deque* pDeq);
extern cstl_error     delete_c_deque ( struct cstl_deque* pDeq);
extern cstl_error     element_at_c_deque (struct cstl_deque* pDeq, int index, void**elem);

extern struct cstl_iterator* new_iterator_c_deque(struct cstl_deque* pDeq);
extern void delete_iterator_c_deque ( struct cstl_iterator* pItr);

#endif
