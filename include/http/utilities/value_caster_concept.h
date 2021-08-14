#pragma once

template <typename S, typename T, template<typename S, typename T> typename V>
concept value_caster_concept = V<S, T>::exists;
