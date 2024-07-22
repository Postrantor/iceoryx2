// Copyright (c) 2024 Contributors to the Eclipse Foundation
//
// See the NOTICE file(s) distributed with this work for additional
// information regarding copyright ownership.
//
// This program and the accompanying materials are made available under the
// terms of the Apache Software License 2.0 which is available at
// https://www.apache.org/licenses/LICENSE-2.0, or the MIT license
// which is available at https://opensource.org/licenses/MIT.
//
// SPDX-License-Identifier: Apache-2.0 OR MIT

#include "iox2/notifier.hpp"
#include "iox/assertions_addendum.hpp"

namespace iox2 {
template <ServiceType S>
Notifier<S>::Notifier(iox2_notifier_h handle)
    : m_handle { handle } {
}

template <ServiceType S>
Notifier<S>::Notifier(Notifier&& rhs) noexcept
    : m_handle { nullptr } {
    *this = std::move(rhs);
}

template <ServiceType S>
auto Notifier<S>::operator=(Notifier&& rhs) noexcept -> Notifier& {
    if (this != &rhs) {
        drop();
        m_handle = std::move(rhs.m_handle);
        rhs.m_handle = nullptr;
    }

    return *this;
}

template <ServiceType S>
Notifier<S>::~Notifier() {
    drop();
}

template <ServiceType S>
auto Notifier<S>::id() const -> UniqueNotifierId {
    IOX_TODO();
}

template <ServiceType S>
auto Notifier<S>::notify() const -> iox::expected<uint64_t, NotifierNotifyError> {
    IOX_TODO();
}

template <ServiceType S>
auto Notifier<S>::notify_with_custom_event_id(EventId event_id) const -> iox::expected<uint64_t, NotifierNotifyError> {
    IOX_TODO();
}

template <ServiceType S>
void Notifier<S>::drop() {
    if (m_handle != nullptr) {
        iox2_notifier_drop(m_handle);
        m_handle = nullptr;
    }
}

template class Notifier<ServiceType::Ipc>;
template class Notifier<ServiceType::Local>;
} // namespace iox2
