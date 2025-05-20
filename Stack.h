#pragma once

#include <deque>
#include <utility>
#include <stdexcept>
#include <type_traits>

template <typename _Ty, typename _Container = std::deque<_Ty>>
class Stack
{
public:
    using value_type = typename _Container::value_type;
    using reference = typename _Container::reference;
    using const_reference = typename _Container::const_reference;
    using size_type = typename _Container::size_type;
    using container_type = _Container;

    Stack();
    explicit Stack(const _Container& cont);
    explicit Stack(_Container&& cont) noexcept(std::is_nothrow_move_constructible<_Container>::value);
    Stack(std::initializer_list<_Ty>);
    ~Stack();

    Stack(const Stack&);
    Stack(Stack&&) noexcept(std::is_nothrow_move_constructible<_Container>::value);

    Stack& operator=(const Stack&);
    Stack& operator=(Stack&&) noexcept(std::is_nothrow_move_constructible<_Container>::value);

    reference top();
    const_reference top() const;

    bool empty() const noexcept;
    size_type size() const noexcept;

    void push(const_reference value);
    void push(value_type&& value) noexcept(std::is_nothrow_move_constructible<value_type>::value);

    template <typename... Args>
    decltype(auto) emplace(Args&&... args);

    void pop();

    void swap(Stack& other) noexcept(noexcept(std::swap(c, other.c)));

    const _Container& container() const noexcept;
    _Container& container() noexcept;

protected:
    _Container c{};
};

template<typename _Ty, typename _Container>
inline Stack<_Ty, _Container>::Stack() = default;

template<typename _Ty, typename _Container>
inline Stack<_Ty, _Container>::Stack(const _Container& cont)
    : c(cont)
{
}

template<typename _Ty, typename _Container>
inline Stack<_Ty, _Container>::Stack(_Container&& cont) noexcept(std::is_nothrow_move_constructible<_Container>::value)
    : c(std::move(cont))
{
}

template<typename _Ty, typename _Container>
inline Stack<_Ty, _Container>::Stack(std::initializer_list<_Ty>) = delete;

template<typename _Ty, typename _Container>
inline Stack<_Ty, _Container>::~Stack() = default;

template<typename _Ty, typename _Container>
inline Stack<_Ty, _Container>::Stack(const Stack&) = default;

template<typename _Ty, typename _Container>
inline Stack<_Ty, _Container>::Stack(Stack&&) noexcept(std::is_nothrow_move_constructible<_Container>::value) = default;

template<typename _Ty, typename _Container>
inline Stack<_Ty, _Container>& Stack<_Ty, _Container>::operator=(const Stack<_Ty, _Container>&) = default;

template<typename _Ty, typename _Container>
inline Stack<_Ty, _Container>& Stack<_Ty, _Container>::operator=(Stack<_Ty, _Container>&&) 
          noexcept(std::is_nothrow_move_constructible<_Container>::value) = default;

template<typename _Ty, typename _Container>
typename Stack<_Ty, _Container>::reference Stack<_Ty, _Container>::top()
{
    if (c.empty())
        throw std::out_of_range("stack::top(): empty stack");
    return c.back();
}

template<typename _Ty, typename _Container>
typename Stack<_Ty, _Container>::const_reference Stack<_Ty, _Container>::top() const
{
    if (c.empty())
        throw std::out_of_range("stack::top(): empty stack");
    return c.back();
}

template<typename _Ty, typename _Container>
inline bool Stack<_Ty, _Container>::empty() const noexcept
{
    return c.empty();
}

template<typename _Ty, typename _Container>
typename Stack<_Ty, _Container>::size_type Stack<_Ty, _Container>::size() const noexcept
{
    return c.size();
}

template<typename _Ty, typename _Container>
inline void Stack<_Ty, _Container>::push(const_reference value)
{
    c.push_back(value);
}

template<typename _Ty, typename _Container>
inline void Stack<_Ty, _Container>::push(value_type&& value) noexcept(std::is_nothrow_move_constructible<value_type>::value)
{
    c.push_back(std::move(value));
}

template<typename _Ty, typename _Container>
inline void Stack<_Ty, _Container>::pop()
{
    if (c.empty())
        throw std::out_of_range("stack::pop() empty stack");
    c.pop_back();
}

template<typename _Ty, typename _Container>
inline void Stack<_Ty, _Container>::swap(Stack& other) noexcept(noexcept(std::swap(c, other.c)))
{
    using std::swap;
    swap(c, other.c);
}

template<typename _Ty, typename _Container>
inline const _Container& Stack<_Ty, _Container>::container() const noexcept
{
    return c;
}

template<typename _Ty, typename _Container>
inline _Container& Stack<_Ty, _Container>::container() noexcept
{
    return c;
}

template<typename _Ty, typename _Container>
template<typename ...Args>
inline decltype(auto) Stack<_Ty, _Container>::emplace(Args && ...args)
{
    return c.emplace_back(std::forward<Args>(args)...);
}

// Специализация std::swap
template <typename _Ty, typename _Container>
void swap(Stack<_Ty, _Container>& lhs, Stack<_Ty, _Container>& rhs) noexcept(noexcept(lhs.swap(rhs)))
{
    lhs.swap(rhs);
}