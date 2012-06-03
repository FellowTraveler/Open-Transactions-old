////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

////////////////////////////////////////////////////////////////////////////////

namespace stlplus
{

  ////////////////////////////////////////////////////////////////////////////////
  // internal holder data structure
  ////////////////////////////////////////////////////////////////////////////////

  template<typename T>
  class smart_ptr_holder
  {
  private:
    unsigned m_count;
    T* m_data;

    // make these private to disallow copying because the holder doesn't know how to copy
    smart_ptr_holder(const smart_ptr_holder& s) :
      m_count(0), m_data(0)
      {
      }

    smart_ptr_holder& operator=(const smart_ptr_holder& s)
      {
        return *this;
      }

  public:
    smart_ptr_holder(T* p = 0) :
      m_count(1), m_data(p)
      {
      }

    ~smart_ptr_holder(void)
      {
        clear();
      }

    unsigned count(void) const
      {
        return m_count;
      }

    void increment(void)
      {
        ++m_count;
      }

    bool decrement(void)
      {
        --m_count;
        return m_count == 0;
      }

    bool null(void)
      {
        return m_data == 0;
      }

    void clear(void)
      {
        if(m_data)
          delete m_data;
        m_data = 0;
      }

    void set(T* p = 0)
      {
        clear();
        m_data = p;
      }

    T*& pointer(void)
      {
        return m_data;
      }

    const T* pointer(void) const
      {
        return m_data;
      }

    T& value(void)
      {
        return *m_data;
      }

    const T& value(void) const
      {
        return *m_data;
      }
  };

  ////////////////////////////////////////////////////////////////////////////////
  // smart_ptr_base class
  ////////////////////////////////////////////////////////////////////////////////

  ////////////////////////////////////////////////////////////////////////////////
  // constructors, assignments and destructors

  // create a null pointer
  template <typename T, typename C>
  smart_ptr_base<T,C>::smart_ptr_base(void) :
    m_holder(new smart_ptr_holder<T>)
  {
  }

  // create a pointer containing a *copy* of the object pointer
  template <typename T, typename C>
  smart_ptr_base<T,C>::smart_ptr_base(const T& data) throw(illegal_copy) :
    m_holder(new smart_ptr_holder<T>)
  {
    m_holder->set(C()(data));
  }

  // create a pointer containing a dynamically created object
  // Note: the object must be allocated *by the user* with new
  // constructor form - must be called in the form smart_ptr<type> x(new type(args))
  template <typename T, typename C>
  smart_ptr_base<T,C>::smart_ptr_base(T* data) :
    m_holder(new smart_ptr_holder<T>)
  {
    m_holder->set(data);
  }

  // copy constructor implements counted referencing - no copy is made
  template <typename T, typename C>
  smart_ptr_base<T,C>::smart_ptr_base(const smart_ptr_base<T,C>& r) :
    m_holder(0)
  {
    m_holder = r.m_holder;
    m_holder->increment();
  }

	// assignment operator - required, else the output of GCC suffers segmentation faults
  template <typename T, typename C>
  smart_ptr_base<T,C>& smart_ptr_base<T,C>::operator=(const smart_ptr_base<T,C>& r) 
  {
    alias(r);
    return *this;
  }

  // destructor decrements the reference count and delete only when the last reference is destroyed
  template <typename T, typename C>
  smart_ptr_base<T,C>::~smart_ptr_base(void)
  {
    if (m_holder && m_holder->decrement())
    {
      delete m_holder;
      m_holder = 0;
    }
  }

  //////////////////////////////////////////////////////////////////////////////
  // logical tests to see if there is anything contained in the pointer since it can be null

  template <typename T, typename C>
  bool smart_ptr_base<T,C>::null(void) const
  {
    return m_holder->null();
  }

  template <typename T, typename C>
  bool smart_ptr_base<T,C>::present(void) const
  {
    return !m_holder->null();
  }

  template <typename T, typename C>
  bool smart_ptr_base<T,C>::operator!(void) const
  {
    return m_holder->null();
  }

  template <typename T, typename C>
  smart_ptr_base<T,C>::operator bool(void) const
  {
    return !m_holder->null();
  }

  //////////////////////////////////////////////////////////////////////////////
  // dereference operators and functions

  template <typename T, typename C>
  T& smart_ptr_base<T,C>::operator*(void) throw(null_dereference)
  {
    if (m_holder->null()) throw null_dereference("null pointer dereferenced in smart_ptr::operator*");
    return m_holder->value();
  }

  template <typename T, typename C>
  const T& smart_ptr_base<T,C>::operator*(void) const throw(null_dereference)
  {
    if (m_holder->null()) throw null_dereference("null pointer dereferenced in smart_ptr::operator*");
    return m_holder->value();
  }

  template <typename T, typename C>
  T* smart_ptr_base<T,C>::operator->(void) throw(null_dereference)
  {
    if (m_holder->null()) throw null_dereference("null pointer dereferenced in smart_ptr::operator->");
    return m_holder->pointer();
  }

  template <typename T, typename C>
  const T* smart_ptr_base<T,C>::operator->(void) const throw(null_dereference)
  {
    if (m_holder->null()) throw null_dereference("null pointer dereferenced in smart_ptr::operator->");
    return m_holder->pointer();
  }

  //////////////////////////////////////////////////////////////////////////////
  // explicit function forms of the above assignment dereference operators

  template <typename T, typename C>
  void smart_ptr_base<T,C>::set_value(const T& data) throw(illegal_copy)
  {
    m_holder->set(C()(data));
  }

  template <typename T, typename C>
  T& smart_ptr_base<T,C>::value(void) throw(null_dereference)
  {
    if (m_holder->null()) throw null_dereference("null pointer dereferenced in smart_ptr::value");
    return m_holder->value();
  }

  template <typename T, typename C>
  const T& smart_ptr_base<T,C>::value(void) const throw(null_dereference)
  {
    if (m_holder->null()) throw null_dereference("null pointer dereferenced in smart_ptr::value");
    return m_holder->value();
  }

  template <typename T, typename C>
  void smart_ptr_base<T,C>::set(T* data)
  {
    m_holder->set(data);
  }

  template <typename T, typename C>
  T* smart_ptr_base<T,C>::pointer(void)
  {
    return m_holder->pointer();
  }

  template <typename T, typename C>
  const T* smart_ptr_base<T,C>::pointer(void) const
  {
    return m_holder->pointer();
  }

  ////////////////////////////////////////////////////////////////////////////////
  // functions to manage counted referencing

  // make this an alias of the passed object
  template <typename T, typename C>
  void smart_ptr_base<T,C>::alias(const smart_ptr_base<T,C>& r)
  {
    _make_alias(r.m_holder);
  }

  template <typename T, typename C>
  bool smart_ptr_base<T,C>::aliases(const smart_ptr_base<T,C>& r) const
  {
    return m_holder == r.m_holder;
  }

  template <typename T, typename C>
  unsigned smart_ptr_base<T,C>::alias_count(void) const
  {
    return m_holder->count();
  }

  template <typename T, typename C>
  void smart_ptr_base<T,C>::clear(void)
  {
    m_holder->clear();
  }

  template <typename T, typename C>
  void smart_ptr_base<T,C>::clear_unique(void)
  {
    if (m_holder->count() == 1)
      m_holder->clear();
    else
    {
      m_holder->decrement();
      m_holder = 0;
      m_holder = new smart_ptr_holder<T>;
    }
  }

  template <typename T, typename C>
  void smart_ptr_base<T,C>::make_unique(void) throw(illegal_copy)
  {
    if (m_holder->count() > 1)
    {
      smart_ptr_holder<T>* old_holder = m_holder;
      m_holder->decrement();
      m_holder = 0;
      m_holder = new smart_ptr_holder<T>;
      if (old_holder->pointer())
        m_holder->set(C()(old_holder->value()));
    }
  }

  template <typename T, typename C>
  void smart_ptr_base<T,C>::copy(const smart_ptr_base<T,C>& data) throw(illegal_copy)
  {
    alias(data);
    make_unique();
  }

  // internal function for distinguishing unique smart_ptr objects
  // used for example in persistence routines

  template <typename T, typename C>
  smart_ptr_holder<T>* smart_ptr_base<T,C>::_handle(void) const
  {
    return m_holder;
  }

  template <typename T, typename C>
  void smart_ptr_base<T,C>::_make_alias(smart_ptr_holder<T>* r_holder)
  {
    // make it alias-copy safe - this means that I don't try to do the
    // assignment if r is either the same object or an alias of it
    if (m_holder != r_holder)
    {
      if (m_holder && m_holder->decrement())
      {
        delete m_holder;
        m_holder = 0;
      }
      m_holder = r_holder;
      m_holder->increment();
    }
  }

  ////////////////////////////////////////////////////////////////////////////////

} // end namespace stlplus
