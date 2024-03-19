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

use std::time::Duration;

use super::{ListenerCreateError, ListenerWaitError, NotifierNotifyError};

pub mod semaphore;

pub trait SignalMechanism {
    fn new() -> Self;
    fn init(&mut self) -> Result<(), ListenerCreateError>;

    fn notify(&self) -> Result<(), NotifierNotifyError>;
    fn try_wait(&self) -> Result<(), ListenerWaitError>;
    fn timed_wait(&self, timeout: Duration) -> Result<(), ListenerWaitError>;
    fn blocking_wait(&self) -> Result<(), ListenerWaitError>;
}
