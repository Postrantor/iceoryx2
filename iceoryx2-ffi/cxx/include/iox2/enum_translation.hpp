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

#ifndef IOX2_ENUM_TRANSLATION_HPP
#define IOX2_ENUM_TRANSLATION_HPP

#include "iox/assertions.hpp"
#include "iox/into.hpp"
#include "iox2/callback_progression.hpp"
#include "iox2/iceoryx2.h"
#include "iox2/internal/iceoryx2.hpp"
// #include "iox2/node.hpp"
#include "iox2/messaging_pattern.hpp"
#include "iox2/node_event.hpp"
#include "iox2/node_failure_enums.hpp"
#include "iox2/semantic_string.hpp"
#include "iox2/service_error_enums.hpp"
#include "iox2/service_type.hpp"

namespace iox {
template <>
constexpr auto from<int, iox2::SemanticStringError>(const int value) noexcept -> iox2::SemanticStringError {
    const auto error = static_cast<iox2_semantic_string_error_e>(value);
    switch (error) {
    case iox2_semantic_string_error_e_INVALID_CONTENT:
        return iox2::SemanticStringError::InvalidContent;
    case iox2_semantic_string_error_e_EXCEEDS_MAXIMUM_LENGTH:
        return iox2::SemanticStringError::ExceedsMaximumLength;
    }

    IOX_UNREACHABLE();
}

template <>
constexpr auto from<int, iox2::ServiceType>(const int value) noexcept -> iox2::ServiceType {
    const auto service_type = static_cast<iox2_service_type_e>(value);
    switch (service_type) {
    case iox2_service_type_e_IPC:
        return iox2::ServiceType::Ipc;
    case iox2_service_type_e_LOCAL:
        return iox2::ServiceType::Local;
    }

    IOX_UNREACHABLE();
}

template <>
constexpr auto
from<iox2::ServiceType, iox2_service_type_e>(const iox2::ServiceType value) noexcept -> iox2_service_type_e {
    switch (value) {
    case iox2::ServiceType::Ipc:
        return iox2_service_type_e_IPC;
    case iox2::ServiceType::Local:
        return iox2_service_type_e_LOCAL;
    }

    IOX_UNREACHABLE();
}

template <>
constexpr auto from<int, iox2::NodeCreationFailure>(const int value) noexcept -> iox2::NodeCreationFailure {
    const auto error = static_cast<iox2_node_creation_failure_e>(value);
    switch (error) {
    case iox2_node_creation_failure_e_INSUFFICIENT_PERMISSIONS:
        return iox2::NodeCreationFailure::InsufficientPermissions;
    case iox2_node_creation_failure_e_INTERNAL_ERROR:
        return iox2::NodeCreationFailure::InternalError;
    }

    IOX_UNREACHABLE();
}

template <>
constexpr auto from<int, iox2::CallbackProgression>(const int value) noexcept -> iox2::CallbackProgression {
    const auto error = static_cast<iox2_callback_progression_e>(value);
    switch (error) {
    case iox2_callback_progression_e_CONTINUE:
        return iox2::CallbackProgression::Continue;
    case iox2_callback_progression_e_STOP:
        return iox2::CallbackProgression::Stop;
    }

    IOX_UNREACHABLE();
}

template <>
constexpr auto from<iox2::CallbackProgression, iox2_callback_progression_e>(
    const iox2::CallbackProgression value) noexcept -> iox2_callback_progression_e {
    switch (value) {
    case iox2::CallbackProgression::Continue:
        return iox2_callback_progression_e_CONTINUE;
    case iox2::CallbackProgression::Stop:
        return iox2_callback_progression_e_STOP;
    }

    IOX_UNREACHABLE();
}

template <>
constexpr auto from<int, iox2::NodeListFailure>(const int value) noexcept -> iox2::NodeListFailure {
    const auto error = static_cast<iox2_node_list_failure_e>(value);
    switch (error) {
    case iox2_node_list_failure_e_INSUFFICIENT_PERMISSIONS:
        return iox2::NodeListFailure::InsufficientPermissions;
    case iox2_node_list_failure_e_INTERNAL_ERROR:
        return iox2::NodeListFailure::InternalError;
    case iox2_node_list_failure_e_INTERRUPT:
        return iox2::NodeListFailure::Interrupt;
    }

    IOX_UNREACHABLE();
}

template <>
constexpr auto from<int, iox2::NodeEvent>(const int value) noexcept -> iox2::NodeEvent {
    const auto error = static_cast<iox2_semantic_string_error_e>(value);
    switch (error) {
    case iox2_node_event_e_TICK:
        return iox2::NodeEvent::Tick;
    case iox2_node_event_e_TERMINATION_REQUEST:
        return iox2::NodeEvent::TerminationRequest;
    case iox2_node_event_e_INTERRUPT_SIGNAL:
        return iox2::NodeEvent::InterruptSignal;
    }

    IOX_UNREACHABLE();
}

template <>
constexpr auto from<iox2::MessagingPattern, iox2_messaging_pattern_e>(const iox2::MessagingPattern value) noexcept
    -> iox2_messaging_pattern_e {
    switch (value) {
    case iox2::MessagingPattern::PublishSubscribe:
        return iox2_messaging_pattern_e_PUBLISH_SUBSCRIBE;
    case iox2::MessagingPattern::Event:
        return iox2_messaging_pattern_e_EVENT;
    }

    IOX_UNREACHABLE();
}

template <>
constexpr auto from<int, iox2::ServiceDetailsError>(const int value) noexcept -> iox2::ServiceDetailsError {
    const auto error = static_cast<iox2_service_details_error_e>(value);
    switch (error) {
    case iox2_service_details_error_e_FAILED_TO_OPEN_STATIC_SERVICE_INFO:
        return iox2::ServiceDetailsError::FailedToOpenStaticServiceInfo;
    case iox2_service_details_error_e_FAILED_TO_READ_STATIC_SERVICE_INFO:
        return iox2::ServiceDetailsError::FailedToReadStaticServiceInfo;
    case iox2_service_details_error_e_FAILED_TO_ACQUIRE_NODE_STATE:
        return iox2::ServiceDetailsError::FailedToAcquireNodeState;
    case iox2_service_details_error_e_FAILED_TO_DESERIALIZE_STATIC_SERVICE_INFO:
        return iox2::ServiceDetailsError::FailedToDeserializeStaticServiceInfo;
    case iox2_service_details_error_e_INTERNAL_ERROR:
        return iox2::ServiceDetailsError::InternalError;
    case iox2_service_details_error_e_SERVICE_IN_INCONSISTENT_STATE:
        return iox2::ServiceDetailsError::ServiceInInconsistentState;
    case iox2_service_details_error_e_VERSION_MISMATCH:
        return iox2::ServiceDetailsError::VersionMismatch;
    }

    IOX_UNREACHABLE();
}

} // namespace iox

#endif
